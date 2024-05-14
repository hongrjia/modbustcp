//
// Created by Administrator on 2024/3/5.
//
extern "C"{
#include "dlfcn.h"
}
#include "../include/reg_info_cell.h"

reg_info_cell::reg_info_cell(json info, reg_base_info bsinfo)
{
//    std::cout << "\n";
//    std::cout << "reg_info:\n " << info.dump() << std::endl;
//    std::cout << "\n";

    /* mobus 协议相关 */
    addr = info["addr"];
    bais = info["bais"];
    precision = info["precision"];
    data_type = info["datatype"]; //

    cell_base_addr = info["baseaddr"];
    /* 内存相关 */
    dataapi_type1 = info["dataapi_type1"];
    dataapi_type2 = info["dataapi_type2"];

    callType = info["callType"]; //
    get_fun_name = info["get"];
    set_fun_name = info["set"];

    ireg_base_info = bsinfo;
    init_fun();
}

int reg_info_cell::get_addr(void)
{
    return addr;
}

int reg_info_cell::get_bais(void)
{
    return bais;
}

int reg_info_cell::get_precision(void)
{
    return precision;
}

string reg_info_cell::get_data_type(void)
{
    return data_type;
}

string reg_info_cell::get_dataapi1_type(void)
{
    return dataapi_type1;
}

string reg_info_cell::get_dataapi2_type(void)
{
    return dataapi_type2;
}

string reg_info_cell::get_dataapi_type(void)
{
    return dataapi_type2;
}

int reg_info_cell::init_fun(void)
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

void reg_info_cell::get_reg_data(int& int_data, float& float_data)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
   // std::cout << BLUE <<  "   " << get_fun_name  << "  addr " << get_addr() << RESET << std::endl;
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

    if ( "ai" == callType)
    {
        int cellno = addr - cell_base_addr;
        if (dataapi_type2 == "float")
        {
            float val_float = 0;
            cel_ai_get_float handle = reinterpret_cast<cel_ai_get_float>(get_handler);
            handle(handle_p, cellno, &val_float);
            float_data = val_float;
        }
    }
    else
    {
        std::cout << RED << "callType error !!!!!!!!!!!!!!!!!!!!!!!!!!" << callType << RESET << std::endl;
    }
    //std::cout << GREEN << "int_data=" << int_data << "    float_data = " << float_data  << "   " << get_fun_name  << "  addr " << get_addr() << RESET << std::endl;
#endif
}

void reg_info_cell::set_reg_data(int int_data, float float_data)
{
    /* 单体类数据不支持写数据 */
}
