//
// Created by Administrator on 2024/2/26.
//
extern "C"{
#include "dlfcn.h"
}

#include "../include/reg_num.h"
#include "../include/reg_info_cell.h"

reg_info_num::reg_info_num(json info, reg_base_info bsif)
{
    reg_base_info baseInfo = bsif;
    int size = info.size();

    if (size) 
    {
        min_addr = max_addr = info[0]["addr"];
    }
    else
    {
        min_addr = max_addr = -1;
    }

    if (size && info[0].contains("param"))  //contains检查key
    {
        /* 单体类数据解析 */
        for (int i = 0; i < size; i++)
        {
            /* 获取首地址 */
            int firstddr = info[i]["addr"];
            int baseaddr = firstddr;
            /*获取个数*/
            json param = info[i]["param"];
            // std::cout << "reg_info \n" << param.dump() << std::endl;

            {
                std::string getfun;
                getfun = param[0]["get"];
                std:cout << "getfun --->" << getfun << "" << std::endl;
                void *dev_handle = dlsym(bsif.dlHandle, string("get_" + bsif.dev_type + "_handle").c_str());

                get_dev_handle3 handle_i = reinterpret_cast<get_dev_handle3>(dev_handle);
                // 设备句柄
                void* handle_p = handle_i(bsif.arrno, bsif.clusterno, bsif.devno);
                // 获取函数
                void* get_handler = dlsym(bsif.dlHandle, getfun.c_str());

                int  count = 0;
                int  flag = 0;
                param_get_int handle = reinterpret_cast<param_get_int>(get_handler);
                handle(handle_p, &count, &flag);
                dzlog_info("count = %d", count);

                for (int k = 0; k < count; k++)
                {
                    //std::cout << "reg_info \n" << info.dump() << std::endl;

                    nlohmann::json cellinfo = {
                            {"addr", firstddr},
                            {"baseaddr", baseaddr},         /*当前单体的第一个地址*/
                            {"bais", info[i]["bais"]},
                            {"precision", info[i]["precision"]},
                            {"get", info[i]["get"]},
                            {"set", info[i]["set"]},
                            {"dataapi_type1", info[i]["dataapi_type1"]},
                            {"dataapi_type2", info[i]["dataapi_type2"]},
                            {"datatype", info[i]["datatype"]},
                            {"callType", info[i]["callType"]},
                    };
                    reg_info_base* reg = new reg_info_cell(cellinfo, baseInfo);
                    firstddr++;
                    reg_list.push_back(reg);
                }
                updateAddr();
            }
        }
    }
    else
    {
        /* 非单体类数据更新 */
        for (int i = 0; i < size ; i++)
        {
            int tmp_addr = info[i]["addr"];
            /* 查找当前设备，当前寄存器类型最小，最大地址 */
            if (tmp_addr > max_addr) max_addr =  tmp_addr;
            if (tmp_addr < min_addr) min_addr = tmp_addr;
            reg_info_base* reg = new reg_info(info[i], baseInfo);
            reg_list.push_back(reg);
        }
    }
    dzlog_info("max_addr = %d, min_addr = %d \n", max_addr, min_addr);
    dzlog_info("--------------------------------reg_list size %d \n", reg_list.size());
}

void reg_info_num::updateAddr(void)
{
    for (auto reg_info : get_reg_list())
    {
        int tmp_addr = reg_info->get_addr();
        if (tmp_addr > max_addr) max_addr =  tmp_addr;
        if (tmp_addr < min_addr) min_addr = tmp_addr;
    }
}

reg_info_num::~reg_info_num()
{
    for (auto reg : reg_list) {
        delete reg;
    }
    reg_list.clear();
    std::cout << "--------------------------------" << "~reg_info_num()" << std::endl;
}

int reg_info_num::get_reg_size(void)
{
    return reg_list.size();
}

void reg_info_num::get_min_max_addr(int& min, int& max)
{
    min = min_addr;
    max = max_addr;
}

std::list<reg_info_base*> reg_info_num::get_reg_list()
{
    return reg_list;
}