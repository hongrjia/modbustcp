//
// Created by Administrator on 2023/11/20.
//
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <fcntl.h>
#include"esmuinf.h"
#include"esmu_data.h"
#include "misc.h"
#include"emu_data.h"
#include"emu_work.h"
#include "pcs_data_all.h"
#include "array_data_all.h"

#include "../include/reg_info_base.h"
#include "../include/gitver.h"
#include "../include/slavedev.h"
#include "../include/slaveManager.h"
#include "../include/modbusServer.h"

#include <thread>
#include <iostream>
#include <fstream>

#include <math.h>

using namespace std;

/***********************************  MACRO ************************************************************/
#define MIN_EMU_MEM_VERSION  (10113)

zlog_category_t *gptLog;

param_get_int funVector[] = {
        emu_parm_get_emu_subsys1_onoff,
        emu_parm_get_emu_subsys2_onoff,
        emu_parm_get_emu_subsys3_onoff,
        emu_parm_get_emu_subsys4_onoff,
        emu_parm_get_emu_subsys5_onoff,
        emu_parm_get_emu_subsys6_onoff,
        emu_parm_get_emu_subsys7_onoff,
        emu_parm_get_emu_subsys8_onoff,
        emu_parm_get_emu_subsys9_onoff,
        emu_parm_get_emu_subsys10_onoff,
        emu_parm_get_emu_subsys11_onoff,
        emu_parm_get_emu_subsys12_onoff,
};

/************************************ PRIVATE FUNC*******************************************************************/
void mis_pcs_sys_ctr_task(void)
{
    while(1)
    {
        void* emu_handle = get_emu_handle(0);
        int val = 0;
        int flag = 1;
        int array_count = 0;
        if (NULL != emu_handle)
        {
            emu_get_arr_cnt(emu_handle, &array_count);
//            std::cout << "array_count: " << array_count << std::endl;
            for (int i = 0; i < array_count; i++)
            {
                void* pcs_handle = get_pcs_handle(-1, -1, i);
                funVector[i](emu_handle, &val, &flag);
                if (pcs_handle && flag)
                {
//                    std::cout << "i = " << i << " -> " << val << std::endl;
                    pcs_param_set_set_ctl(pcs_handle, val, flag);
                }
            }
        }
        // std::cout << "mis_pcs_sys_ctr_task " << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

slavedev* getOneUseDev(void)
{
    slavedev* dev = nullptr;
    modbus_server* svr = modbus_server::GetInstance();
    if (svr)
    {
        slaveManager* ma = svr->getSlavemanager();
        if (ma)
        {
            dev = ma->findSlave(42);
            if (dev)
            {
                std::cout << "find dev id " << dev->getSlaveId() << std::endl;
                return dev;
            }
            else
            {
                std::cout << "dev is null" << std::endl;
                return nullptr;
            }
        }
        else
        {
                std::cout << "ma is null" << std::endl;
                return nullptr;
        }
    }
    else
    {
        std::cout << "svr is null" << std::endl;
        return nullptr;
    }
}

/* 甬能 modbus tcp 的数据汇总服务 */
void mis_task_for_yongneng(void)
{
    slavedev* dev  =  getOneUseDev();
    if (dev != NULL)
    {
        while(1)
        {
            void* emu_handle = get_emu_handle(0);
            int ret = 0;
            int arr_count = 0;
            int flag = 1;

            // 地址从 输入寄存器 10（0x0a） 开始
            int addr = 10;
            uint16_t uint_val = 0;
            int16_t int_val = 0;

            ret = emu_parm_get_emu_arr_cnt(emu_handle, &arr_count, &flag);
            if (0 == ret)
            {
                float array_all_cur_a = 0;  /* 当前系统所有电流汇总 */
                float array_all_pow = 0;    /* 全站储能额定功率 */
                float array_all_cap = 0;   /* 全站储能额定容量 */
                float SiteReactiveIncrement = 0; /* 全站储能可增无功值 */
                float WholeSiteReactiveDecrement = 0;  /* 全站储能可减无功值 */
                float max_power_charge_time = 0;  /* 全站 全站储能最大功率放电可用时间 */
                float max_power_dis_charge_time = 0;  /* 全站 全站储能最大功率放电可用时间 */
                for (int i = 0; i < arr_count; i++)
                {
                    // 全站储能电流
                    void* arr_handle = get_array_handle(-1, -1, i);
                    float cur_a = 0;

                    ret = array_ai_get_arrcur(arr_handle, &cur_a);
                    if (0 == ret)
                    {
                        array_all_cur_a += cur_a;
                    }

                    // 全站储能额定功率
                    float array_pow = 0;
                    ret = array_parm_get_pcs_endispow(arr_handle, &array_pow, &flag);
                    if (0 == ret)
                    {
                        array_all_pow += array_pow;
                    }

                    // 全站储能额定容量
                    float array_cap = 0;
                    ret = array_ai_get_arrcap(arr_handle, &array_cap);
                    if (0 == ret)
                    {
                        array_all_cap += array_cap;
                    }
                    // 全站储能可增无功值
                    SiteReactiveIncrement = 0;

                    // 全站储能可减无功值
                    WholeSiteReactiveDecrement = 0;

                    // 全站储能最大功率充电可用时间
                    {
                        float chg_cap = 0;
                        float max_pow = 0;
                        float time = 0;
                        // 获取可冲电量
                        ret = array_ai_get_arrenchg_cap(arr_handle, &chg_cap);
                        // 获取最大的可冲功率
                        ret |= array_parm_get_pcs_enchgpow(arr_handle, &max_pow, &flag);
                        if (0 == ret)
                        {
                            if (max_pow != 0)
                            {
                                time  = fabs(chg_cap) * 1.0  / fabs(max_pow);
                                max_power_charge_time += time;
                            }
                        }
                    }

                    // 全站储能最大功率放电可用时间
                    {
                        float dischg_cap = 0;
                        float dis_max_pow = 0;
                        int dis_time = 0;
                        // 获取可冲电量
                        ret = array_ai_get_arrendis_cap(arr_handle, &dischg_cap);
                        // 获取最大的可放功率
                        ret |= array_parm_get_pcs_endispow(arr_handle, &dis_max_pow, &flag);
                        if (0 == ret)
                        {
                            if (dis_max_pow != 0)
                            {
                                dis_time = fabs(dischg_cap) * 1.0 / fabs(dis_max_pow);
                                max_power_dis_charge_time += dis_time;
                            }
                        }
                    }
                }


                int_val = array_all_cur_a * 10;
                addr = 10;
                dev->setInputRegisterValue(addr, int_val);
                std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

                addr = 11;
                int_val = array_all_pow * 10;
                dev->setInputRegisterValue(addr, int_val);
                std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;


                addr = 12;
                int_val = array_all_cap * 10;
                dev->setInputRegisterValue(addr, int_val);
                std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;


                addr = 13;
                int_val = SiteReactiveIncrement * 10;
                dev->setInputRegisterValue(addr, int_val);
                std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

                addr = 14;
                int_val = WholeSiteReactiveDecrement * 10;
                dev->setInputRegisterValue(addr, int_val);
                std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;


                addr = 16;
                int_val = max_power_charge_time * 10;
                dev->setInputRegisterValue(addr, int_val);
                std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;


                addr = 15;
                int_val = max_power_dis_charge_time * 10;
                dev->setInputRegisterValue(addr, int_val);
                std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;
            }

            // 全站储能单元总数
            int bcm_count = 0;
            bcm_count = arr_count;

            addr = 17;
            int_val = arr_count;
            int_val *= 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

            // 全站可用储能单元总数
            int normal_count = 0;
            for (int i = 0; i < arr_count; i++)
            {
                int status = -1;
                void* arr_handle = get_array_handle(-1, -1, i);
                ret = array_ai_get_arrstate(arr_handle, &status);
                if (0 == ret)
                {
                    if (4 != status)
                    {
                        normal_count++;
                    }
                }
            }
            addr = 18;
            int_val = normal_count;
            int_val *= 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;


            // 全站PCS总台数
            int pcs_count = 0;
//            emu_parm_get_emu_pcs_master_cnt(emu_handle, &pcs_count, &flag);
            pcs_count = arr_count;
            addr = 19;
            int_val = pcs_count;
            int_val *= 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

            // 全站可用储能PCS总数
            int pcs_available_cnt = 0;
            for (int i = 0; i < pcs_count; i++)
            {
                void* pcs_handle = get_pcs_handle(-1, -1, i);
                if (pcs_handle)
                {
                    int pcs_status = 0;
                    ret = pcs_ai_get_run_sta(pcs_handle, &pcs_status);
                    if (pcs_status != 2 && (0 <= pcs_status) && (pcs_status <= 6))
                    {
                        pcs_available_cnt++;
                    }
                }
            }

            addr = 20;
            int_val = pcs_available_cnt;
            int_val *= 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

            // 全站储能当前可放电量
            float all_arrenchg_cap = 0;
            for (int i = 0; i < arr_count; i++)
            {
                void* array_handle = get_array_handle(-1, -1, i);
                if (array_handle)
                {
                    float arrenchg_cap = 0;
                    ret = array_ai_get_arrenchg_cap(array_handle, &arrenchg_cap);
                    if (0 == ret)
                    {
                        all_arrenchg_cap += fabs(arrenchg_cap);
                    }
                }
            }

            addr = 22;
            int_val = all_arrenchg_cap * 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

            // 全站储能当前可充电量
            float all_arrendis_cap = 0;
            for (int i = 0; i < arr_count; i++)
            {
                void* array_handle = get_array_handle(-1, -1, i);
                if (array_handle)
                {
                    float arrendischg_cap = 0;
                    ret = array_ai_get_arrendis_cap(array_handle, &arrendischg_cap);
                    if (0 == ret)
                    {
                        all_arrendis_cap += fabs(arrendischg_cap);
                    }
                }
            }
            addr = 21;
            int_val = all_arrendis_cap * 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

            // 全站储能当日放电量
            float all_arr_day_dis_chg_cap = 0;
            for (int i = 0; i < arr_count; i++)
            {
                void* array_handle = get_array_handle(-1, -1, i);
                if (array_handle)
                {
                    float arr_day_dis_chg_cap = 0;
                    ret = array_ai_get_arrdaydis_cap(array_handle, &arr_day_dis_chg_cap);
                    if (0 == ret)
                    {
                        all_arr_day_dis_chg_cap += fabs(arr_day_dis_chg_cap);
                    }
                }
            }
            addr = 23;
            int_val = all_arr_day_dis_chg_cap * 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

            // 全站储能当日充电量
            float all_arr_day_chg_cap = 0;
            for (int i = 0; i < arr_count; i++)
            {
                void* array_handle = get_array_handle(-1, -1, i);
                if (array_handle)
                {
                    float arr_day_chg_cap = 0;
                    ret = array_ai_get_arrdaychg_cap(array_handle, &arr_day_chg_cap);
                    if (0 == ret)
                    {
                        all_arr_day_chg_cap += fabs(arr_day_chg_cap);
                    }
                }
            }
            addr = 24;
            int_val = all_arr_day_chg_cap * 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

            // 全站储能有功控制目标返回值
            float all_ctr_pcs_power = 0;
            addr = 25;
            void* ihandle = get_pcs_handle(-1, -1, 0);
            pcs_ai_get_out_pow_p(ihandle, &all_ctr_pcs_power);
            int_val = all_ctr_pcs_power * 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

            // 全站储能 soc 上限
            float max_soc = 100;

            addr = 26;
            int_val = max_soc * 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

            // 全站储能 soc 下限
            float min_soc = 0;
            addr = 27;
            int_val = min_soc * 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

            // 全站储能有功功率实际值
            float all_pcs_power = 0;
            for (int i = 0; i < pcs_count; i++)
            {
                void* pcs_handle = get_pcs_handle(-1, -1, i);
                if (pcs_handle)
                {
                    float pcs_power = 0;
                    std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

                    ret = pcs_ai_get_out_pow_p(pcs_handle, &pcs_power);
                    if (0 == ret)
                    {
                        std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

                        all_pcs_power += pcs_power;
                    }
                }
            }
            addr = 28;
            int_val = all_pcs_power * 10;
            dev->setInputRegisterValue(addr, int_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "-------------->" <<  int_val << std::endl;

            // 1# 目前甬能只有一个堆，先按一堆进行处理
            void* array_handle = get_array_handle(-1, -1, 0);
            if (array_handle)
            {
                // 远方就地控制信号  02 功能码
                addr = 123;
                int_val = 0;
                int sig = 0;
                pcs_ai_get_remote_mode(get_pcs_handle(-1, -1, 0), &sig);
                dev->setTab_Input_Bits(addr, sig);

                // 并离网状态信号
                addr = 124;
                int_val = 0;
                sig = 0;
                pcs_ai_get_fgr_sta(get_pcs_handle(-1, -1, 0), &sig);
                dev->setTab_Input_Bits(addr, sig);

                int status = 0;
                int flag = 0;
                array_parm_get_bms_state(array_handle, &status, &flag);

                array_ai_get_arrstate(array_handle, &status);
                // 故障状态
                if (4 == status)
                {
                    dev->setTab_Input_Bits(125, 1);  // 故障状态
                    dev->setTab_Input_Bits(126, 1); // 异常
                    dev->setTab_Input_Bits(127, 0); // 停机
                    dev->setTab_Input_Bits(128, 0); // 待机
                    dev->setTab_Input_Bits(129, 0); // 充电
                    dev->setTab_Input_Bits(130, 0); // 放电
                }
                // 停机状态
                if (0 == status)
                {
                    dev->setTab_Input_Bits(125, 0);  // 故障状态
                    dev->setTab_Input_Bits(126, 0); // 异常
                    dev->setTab_Input_Bits(127, 1); // 停机
                    dev->setTab_Input_Bits(128, 0); // 待机
                    dev->setTab_Input_Bits(129, 0); // 充电
                    dev->setTab_Input_Bits(130, 0); // 放电
                }

                // 待机状态
                if (3 == status)
                {
                    dev->setTab_Input_Bits(125, 0);  // 故障状态
                    dev->setTab_Input_Bits(126, 0); // 异常
                    dev->setTab_Input_Bits(127, 0); // 停机
                    dev->setTab_Input_Bits(128, 1); // 待机
                    dev->setTab_Input_Bits(129, 0); // 充电
                    dev->setTab_Input_Bits(130, 0); // 放电
                }

                // 充电状态
                if (1 == status)
                {
                    dev->setTab_Input_Bits(125, 0);  // 故障状态
                    dev->setTab_Input_Bits(126, 0); // 异常
                    dev->setTab_Input_Bits(127, 0); // 停机
                    dev->setTab_Input_Bits(128, 0); // 待机
                    dev->setTab_Input_Bits(129, 1); // 充电
                    dev->setTab_Input_Bits(130, 0); // 放电
                }

                // 放电状态
                if (2 == status)
                {
                    dev->setTab_Input_Bits(125, 0);  // 故障状态
                    dev->setTab_Input_Bits(126, 0); // 异常
                    dev->setTab_Input_Bits(127, 0); // 停机
                    dev->setTab_Input_Bits(128, 0); // 待机
                    dev->setTab_Input_Bits(129, 0); // 充电
                    dev->setTab_Input_Bits(130, 1); // 放电
                }

                if (2 == status || 1 == status)
                {
                    // 4249 储能开关
                    dev->setTab_Input_Bits(4249, 1); // 放电
                }
                else
                {
                    dev->setTab_Input_Bits(4249, 0); // 放电
                }
            }

            void* pcs_handle = get_pcs_handle(-1, -1, 0);
            if (pcs_handle)
            {
                // 电压
                float ivol = 0;
                pcs_ai_get_ac_uw_vol(pcs_handle, &ivol);
                int_val = ivol * 10;
                dev->setInputRegisterValue(29, int_val);

                float ival = 0;
                pcs_ai_get_ac_u_cur(pcs_handle, &ival);
                int_val = ival * 10;
                // 电流
                dev->setInputRegisterValue(30, int_val);
            }

            // 设置禁冲禁放状态
            // 禁止充
            int chg_status = 0;
            array_di_get_notchg(array_handle, &chg_status);
            int_val = chg_status;
            dev->setTab_Input_Bits(4250, int_val);

            // 禁止放
            int dis_status = 0;
            array_di_get_notdis(array_handle, &dis_status);
            int_val = dis_status;
            dev->setTab_Input_Bits(4251, int_val);

            // 系统最大充放电功率 133 144
            float dat = 0;
            emu_parm_get_emu_enup_p(emu_handle, &dat, &flag);
            int_val = dat * 10;
            dev->setInputRegisterValue(133, int_val);

            emu_parm_get_emu_enlow_p(emu_handle, &dat, &flag);
            int_val = dat * 10;
            dev->setInputRegisterValue(134, int_val);

            // 累计总充电量
            dat = 0;
            int32_t int32_val = 0;

            // 累计总放电量
            array_ai_get_arrdis_cap(array_handle, &dat);
            int32_val = dat * 10;
            dev->setInputRegisterValue(2227, int32_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "aaaaa-------------->" <<  int32_val << std::endl;

            array_ai_get_arrchg_cap(array_handle, &dat);
            int32_val = dat * 10;
            dev->setInputRegisterValue(2229, int32_val);
            std::cout << "lines:" << __LINE__ << "addr:" << addr << "aaaaaa-------------->" <<  int32_val << std::endl;

            // 保护动作信号
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
}
/************************************PUBLIC FUNC *********************************************************************/
/***
 * @func    EMU设定的控制源
 * @param   iEmuNo     EMU编号默认0
 * @param   iState     控制源状态
 * @return  0成功 -1失败
 */
int GetRamEmuSrcMod(int iEmuNo,int* iState){
    int iFlag;
    int iRunMod;
    int iRet;
    void* ptHandle = get_emu_handle(iEmuNo);
    if(EMU_RET_SUC != emu_parm_get_emu_src_cod(ptHandle,iState,&iFlag)) {
        return -1;
    }
    return 0;
}

int ems_work_mode_local(void)
{
    int src = 0;
    if(-1 == GetRamEmuSrcMod(0,&src)) {
        return 0;
    }
    return src == 1 ? 0 : 1;
}

int IsProcessRunning() {
    int fd_lock = open("modbusvr.lock",O_CREAT|O_RDWR,0666);
    int rc = flock(fd_lock,LOCK_EX|LOCK_NB);
    if(rc)
    {
        printf("Process Already Running !\n");
        return -1;
    }
    return 0;
}
/***
 * @func    mic_task_init
 * @details modbus 附带数据汇总服务
 * @return
 */
int mic_task_init(void)
{
    int emuVer = emu_get_shm_version();
    if (MIN_EMU_MEM_VERSION <= emuVer)
    {
        std::thread i_thread;
        i_thread = std::thread(mis_pcs_sys_ctr_task);
        i_thread.detach();
    }
}

int mic_modbus_task(void)
{
    // 甬能 modbus 定制
    std::thread work_thread;
    work_thread = std::thread(mis_task_for_yongneng);
    work_thread.detach();
    return 0;
}

void gitVer(void)
{
    system("mkdir -p /tmp/esccuversion");

    ofstream file("/tmp/esccuversion/modbus-tcp-slave.ver");
    file << "[gitDate] = " << GIT_DATE << endl;
    file << "[commitID] = " << GIT_SHA1 << endl;
    file << "[gitBranch] = " << GIT_BRANCH << endl;
    file << "[gitUrl] = " << GIT_REMOTE << endl;
    file.close();
}

/***
 * @func    初始化日志系统
 * @return  -1错误 0成功
 */
int InitLog() {
    int iRet = dzlog_init("modbus_log.conf", "modbus_log");
    if (iRet != 0) {
        printf("zlog_init ret error :%d\n",iRet);
        return -1;
    }
    return 0;
}