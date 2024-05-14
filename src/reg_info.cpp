//
// Created by Administrator on 2024/2/26.
//
extern "C"{
#include "dlfcn.h"
}
#include "../include/reg_info.h"
#include "../include/reg_num.h"
#include "../include/cconfig.h"
#include "../include/util.h"

reg_info::reg_info(json info, reg_base_info bsinfo)
{
    //std::cout << "reg_info:\n " << info.dump() << std::endl;
     /* mobus 协议相关 */
    addr = info["addr"];
    bais = info["bais"];
    precision = info["precision"];
    data_type = info["datatype"];

    /* 内存相关 */
    dataapi_type = info["dataapi_type"];
    callType = info["callType"];
    get_fun_name = info["get"];
    set_fun_name = info["set"];
    msg_cn = get_fun_name + "_" + std::to_string(addr);
    msg_en = msg_cn;

    if (info.contains("dataname"))
    {
        msg_cn = info["dataname"];
    }
   if (info.contains("dataname_en"))
    {
        msg_en = info["dataname_en"];
    }

    ireg_base_info = bsinfo;
    init_fun();
}

int reg_info::get_addr(void)
{
    return addr;
}

int reg_info::get_bais(void)
{
    return bais;
}

int reg_info::get_precision(void)
{
    return precision;
}

string reg_info::get_data_type(void)
{
    return data_type;
}

string reg_info::get_dataapi_type(void)
{
    return dataapi_type;
}

int reg_info::init_fun(void)
{
    void *dlHandle = ireg_base_info.dlHandle;
    dev_handle = dlsym(dlHandle, string("get_" + ireg_base_info.dev_type + "_handle").c_str());
    if (NULL == dev_handle)
    {
        cerr << "Cannot dlsym function: " << dlerror() << '\n';
        throw "加载handle函数错误:"+ string("get_"+ ireg_base_info.dev_type +"_handle")+"\n";
    }
    
    get_handler = dlsym(dlHandle, get_fun_name.c_str());
    set_handler = dlsym(dlHandle, set_fun_name.c_str());
    
    if ((NULL == get_handler) || (NULL == set_handler))
    {
        std::cout << " get_handler is null or  set_handler is null " << get_fun_name << "  "  << set_fun_name << "  "<<std::endl;
        throw "加载handle函数错误:" + get_fun_name + "or " + set_fun_name +"\n";
    }
}

void reg_info::get_reg_data(int& int_data, float& float_data)
{
    std::lock_guard<std::mutex> mutex(i_mutex);

//    std::cout << YELLOW <<  "   " << get_fun_name  << "  addr " << get_addr() << RESET << std::endl;
//    std::cout << GREEN << ireg_base_info.arrno << "------->"<< ireg_base_info.clusterno << "------->" << ireg_base_info.devno << "------->" << ireg_base_info.dev_type << std::endl;
#if 1
    void* handle_p = NULL;
    if (("array" == ireg_base_info.dev_type) || ("emu" == ireg_base_info.dev_type))
    {
        get_dev_handle1 handle_i = reinterpret_cast<get_dev_handle1>(dev_handle);
        handle_p = handle_i(ireg_base_info.devno);
    }
    else if ("cluster" == ireg_base_info.dev_type)
    {
        get_dev_handle2 handle_i = reinterpret_cast<get_dev_handle2>(dev_handle);
        handle_p = handle_i(ireg_base_info.arrno, ireg_base_info.clusterno);
    }
    else
    {
        get_dev_handle3 handle_i = reinterpret_cast<get_dev_handle3>(dev_handle);
        handle_p = handle_i(ireg_base_info.arrno, ireg_base_info.clusterno, ireg_base_info.devno);
    }


    if (( "ai" == callType) || ("di" == callType) )
    {
        if (dataapi_type == "float")
        {
            float val_float = 0;
            get_float handle = reinterpret_cast<get_float>(get_handler);
            handle(handle_p, &val_float);
            float_data = val_float;
        }

        if (dataapi_type == "int")
        {
            int val_int = 0;
            get_int handle = reinterpret_cast<get_int>(get_handler);
            handle(handle_p, &val_int);
            int_data = val_int;
        }
    }

    else if ("param" == callType || "parm" == callType)
    {
        if (dataapi_type == "float")
        {
            float val_float = 0;
            int flag = 0;
            param_get_float handle = reinterpret_cast<param_get_float>(get_handler);
            handle(handle_p, &val_float, &flag);
            float_data = val_float;
        }

        if (dataapi_type == "int")
        {
            int val_int = 0;
            int flag = 0;
            param_get_int handle = reinterpret_cast<param_get_int>(get_handler);
            handle(handle_p, &val_int, &flag);
            int_data = val_int;
        }
    }
    else
    {
        std::cout << RED << "callType error !!!!!!!!!!!!!!!!!!!!!!!!!!" << callType << RESET << std::endl;
    }
    //std::cout << YELLOW << "int_data=" << int_data << "    float_data = " << float_data  << "   " << get_fun_name  << "  addr " << get_addr() << RESET << std::endl;
#endif
}

void reg_info::set_reg_data(int int_data, float float_data)
{
    // std::cout << "set_reg_data" << set_fun_name << "int_data=" << int_data << "float_data " << float_data <<  std::endl;
    std::lock_guard<std::mutex> mutex(i_mutex);

    void* handle_p = NULL;
    if (("array" == ireg_base_info.dev_type) || ("emu" == ireg_base_info.dev_type))
    {
        get_dev_handle1 handle_i = reinterpret_cast<get_dev_handle1>(dev_handle);
        handle_p = handle_i(ireg_base_info.devno);
    }
    else if ("cluster" == ireg_base_info.dev_type)
    {
        get_dev_handle2 handle_i = reinterpret_cast<get_dev_handle2>(dev_handle);
        handle_p = handle_i(ireg_base_info.arrno, ireg_base_info.clusterno);
    }
    else
    {
        get_dev_handle3 handle_i = reinterpret_cast<get_dev_handle3>(dev_handle);
        handle_p = handle_i(ireg_base_info.arrno, ireg_base_info.clusterno, ireg_base_info.devno);
    }

    if (( "ai" == callType) || ("di" == callType) )
    {
        if (dataapi_type == "float")
        {
            set_float handle = reinterpret_cast<set_float>(set_handler);
            handle(handle_p, float_data);
        }

        if (dataapi_type == "int")
        {
            set_int handle = reinterpret_cast<set_int>(set_handler);
            handle(handle_p, int_data);
        }
        report_event();
    }
    else if ("param" == callType || "parm" == callType)
    {
        if (dataapi_type == "float")
        {
            int flag = 1;
            param_set_float handle = reinterpret_cast<param_set_float>(set_handler);
            handle(handle_p, float_data, flag);
        }

        if (dataapi_type == "int")
        {
            int flag = 1;
            param_set_int handle = reinterpret_cast<param_set_int>(set_handler);
            handle(handle_p, int_data, flag);
        }
        report_event();
    }
    else
    {
        std::cout << GREEN << "callType error !!!!!!!!!!!!!!!!!!!!!!!!!!" << callType << RESET << std::endl;
        return;
    }

    clock_gettime(CLOCK_MONOTONIC, &g_tend);
    char buf[128] = {0};

    sprintf(buf, "./ %s-%d-%f-proc.log", set_fun_name.c_str(), int_data, float_data);
    dzlog_info("%s: %ldms\n", buf,
           DiffNS(g_tbegin, g_tend) / NSECS_PER_MSEC);

    dzlog_info("DiffNS(g_tbegin, g_tend) %d ns",  DiffNS(g_tbegin, g_tend));

    char timeStart[200] = {0};
    struct timeval time;
    gettimeofday(&time, NULL);

    pTempTmEnd = localtime(&time.tv_sec);
    if (NULL != pTempTmEnd) {
        snprintf(timeStart, 199, "%04d-%02d-%02d %02d:%02d:%02d.%03ld",
                 pTempTmEnd->tm_year + 1900,
                 pTempTmEnd->tm_mon + 1,
                 pTempTmEnd->tm_mday,
                 pTempTmEnd->tm_hour,
                 pTempTmEnd->tm_min,
                 pTempTmEnd->tm_sec,
                 time.tv_usec / 1000);
    }
    dzlog_info("[%s][%d], system protect end time:[%s], start-end=%.3f秒\n", __FUNCTION__, __LINE__, timeStart,
           difftime((time_t) pTempTmStr, (time_t) pTempTmEnd));
}

void reg_info::report_event(void)
{
    // soe 事件上报
    soe* isoe = soe::GetInstance();
    if (isoe)
    {
        std::string lang = cconfig::GetInstance()->GetString("LNG");
        if ("EN" == lang)
        {
            isoe->report_event(ireg_base_info.arrno, ireg_base_info.clusterno, ireg_base_info.devno, 4, SOE_BASE_ID + addr, 3, msg_en);
        }
        else
        {
            isoe->report_event(ireg_base_info.arrno, ireg_base_info.clusterno, ireg_base_info.devno, 4, SOE_BASE_ID + addr, 3, msg_cn);
        }
    }
}