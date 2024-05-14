//
// Created by Administrator on 2024/2/26.
//

#ifndef MODBUS_SERVER_REG_INFO_H
#define MODBUS_SERVER_REG_INFO_H

#include<iostream>
#include<string>
#include<functional>
#include<list>
#include <mutex>
#include "json.hpp"
#include "jsonparser.h"
#include "reg_info_base.h"
#include "misc.h"

using namespace std;
using namespace nlohmann;

class reg_info : public reg_info_base
{
public:
    reg_info(json info, reg_base_info bsinfo);
    void get_reg_data(int& int_data, float& float_data);
    void set_reg_data(int int_data, float float_data);

    int get_addr(void);
    int get_bais(void);
    int get_precision(void);
    string get_data_type(void);
    string get_dataapi_type(void);

private:
    int init_fun(void);
    void report_event(void);
private:
    /* modbus tcp 协议相关 */
    int addr;
    string data_type;
    int bais;       /* 偏移 */
    int precision;  /* 精度 */

    /* 内存相关 */
    string dataapi_type;
    string callType;
    string get_fun_name;
    string set_fun_name;
    reg_base_info ireg_base_info;

    string msg_cn;  /* 事件上报中文名称 */
    string msg_en; /* 事件上报英文名称 */

    /* 6 类函数指针 */
    void* get_handler;
    void* set_handler;
    void* dev_handle;

    /* lock */
    std::mutex i_mutex;
};

#endif //MODBUS_SERVER_REG_INFO_H
