//
// Created by Administrator on 2024/2/26.
//

#ifndef MODBUS_SERVER_REG_NUM_H
#define MODBUS_SERVER_REG_NUM_H

#include "reg_info.h"
#include "reg_info_base.h"
#include "misc.h"

class reg_info_num{
public:
    reg_info_num(json info, reg_base_info bsif);
    ~reg_info_num();
    int get_reg_size(void);
    void get_min_max_addr(int& min, int& max);
    std::list<reg_info_base*> get_reg_list();
private:
    string dev_name;
    int arrno;
    int clusterno;
    int devno;
    std::list<reg_info_base*> reg_list;
    void *dlHandle;
    int min_addr{-1};
    int max_addr{-1};
private:
    void updateAddr(void);
};

#endif //MODBUS_SERVER_REG_NUM_H
