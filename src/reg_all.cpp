//
// Created by Administrator on 2024/2/26.
//

#include "../include/reg_all.h"
extern "C"{
#include "dlfcn.h"
}
#include <sstream>

reg_all::reg_all(json info)
{
    slave_id = info["slave_id"];
    dev_name = info["dev_name"];
    arrno = info["array"];
    clusterno = info["cluster"];
    devno = info["dev"];
    
    reg_base_info bsif;
    bsif.arrno = arrno;
    bsif.clusterno = clusterno;
    bsif.devno = devno;
    bsif.dev_type = dev_name;

    /* 获取动态库句柄 */
    string devlib ="lib"+ dev_name + "shm.so";
    dlHandle = dlopen(devlib.c_str(), RTLD_LAZY); //打开动态库并延时加载
    if (!dlHandle)
    {
        cerr << "Cannot open library: " << dlerror() << '\n';
        throw "加载动态库错误:"+ devlib + "\n";
    }

    bsif.dlHandle = dlHandle;

    input_reg = new reg_info_num(info["input_reg_info"], bsif);
    coil_reg = new reg_info_num(info["coil_reg_info"], bsif);
    hold_reg = new reg_info_num(info["hold_reg_info"], bsif);
    dis_input_reg = new reg_info_num(info["discrete_input_reg_info"], bsif);

    cout << "-----------------------------reg_all--- slave id: " << slave_id << dev_name << "_" << arrno << "_"  << clusterno << "_"  << devno << "-------------------------" << endl;
}

reg_info_num* reg_all::get_input_reg(void)
{
    return input_reg;
}

reg_info_num* reg_all::get_coil_reg(void)
{
    return coil_reg;
}

reg_info_num* reg_all::get_dis_input_reg(void)
{
    return dis_input_reg;
}

reg_info_num* reg_all::get_hold_reg(void)
{
    return hold_reg;
}

bool reg_all::get_reg_count(string type, int& count)
{
    if ("input_reg_info" == type)
    {
        count = input_reg->get_reg_size();
    }

    if ("coil_reg_info" == type)
    {
        count = coil_reg->get_reg_size();
    }

    if ("hold_reg_info" == type)
    {
        count = dis_input_reg->get_reg_size();
    }

    if ("discrete_input_reg_info" == type)
    {
        count = hold_reg->get_reg_size();
    }
}

void reg_all::get_min_max_addr(
    int& min_input, int& max_input,
    int& min_coil, int& max_coil,
    int& min_hold, int& max_hold,
    int& min_dis_input, int& max_dis_input)
{
    input_reg->get_min_max_addr(min_input, max_input);
    coil_reg->get_min_max_addr(min_coil, max_coil);
    hold_reg->get_min_max_addr(min_hold, max_hold);
    dis_input_reg->get_min_max_addr(min_dis_input, max_dis_input);
}

std::string reg_all::get_info(void)
{
     return std::to_string(slave_id) + "_" + dev_name + "_" + std::to_string(arrno) + "_" + std::to_string(clusterno) + "_" + std::to_string(devno) + "  ";
}

void reg_all::printInfo(void)
{
    std::stringstream ss;
    ss << get_info() << std::endl;
    ss << "get_input_reg size " << std::to_string(get_input_reg()->get_reg_size()) << std::endl;
    ss << "get_coil_reg size " << std::to_string(get_coil_reg()->get_reg_size()) << std::endl;
    ss << "get_dis_input_reg size " << std::to_string(get_dis_input_reg()->get_reg_size()) << std::endl;
    ss << "get_hold_reg size " << std::to_string(get_hold_reg()->get_reg_size()) << std::endl;
    dzlog_info("%s", ss.str().c_str());
}

reg_all::~reg_all()
{
    delete input_reg;
    delete coil_reg;
    delete dis_input_reg;
    delete hold_reg;
    dlclose(dlHandle);
}
