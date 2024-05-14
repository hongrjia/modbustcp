//
// Created by Administrator on 2024/2/26.
//

#ifndef MODBUS_SERVER_REG_ALL_H
#define MODBUS_SERVER_REG_ALL_H

#include "reg_num.h"
#include "misc.h"

class reg_all{
private:
    int slave_id;
    std::string dev_name;
    int arrno;
    int clusterno;
    int devno;
    void* dlHandle;
    std::string devinfo;
    reg_info_num* input_reg{};
    reg_info_num* coil_reg{};
    reg_info_num* dis_input_reg{};
    reg_info_num* hold_reg{};
public:
    reg_all(json info); //有参
    ~reg_all();
    bool get_reg_count(string type, int& count);
    void get_min_max_addr(int& min_input, int& max_input, int& min_coil, int& max_coil, int& min_hold, int& max_hold, int& min_dis_input, int& max_dis_input);
    std::string get_info(void);
    reg_info_num* get_input_reg(void);
    reg_info_num* get_coil_reg(void);
    reg_info_num* get_dis_input_reg(void);
    reg_info_num* get_hold_reg(void);
    void printInfo(void);
};

#endif //MODBUS_SERVER_REG_ALL_H
