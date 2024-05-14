//
// Created by Administrator on 2024/3/5.
//

#ifndef MODBUS_SERVER_REG_INFO_BASE_H
#define MODBUS_SERVER_REG_INFO_BASE_H

#include <string>
#include<functional>
#include "soe.h"
#include "misc.h"

using namespace std;

typedef int     (*set_float)(void *, float);
typedef int     (*get_float)(void *, float *);
typedef int     (*set_int)(void *, int);
typedef int     (*get_int)(void *, int *);
typedef int     (*cel_ai_get_float)(void *, int, float *);
typedef int     (*param_set_int)(void *, int, int);
typedef int     (*param_get_int)(void *, int *, int *);
typedef int     (*param_set_float)(void *, float, int);
typedef int     (*param_get_float)(void *, float *, int *);
typedef void*   (*get_dev_handle3)(int, int, int);
typedef void*   (*get_dev_handle2)(int,int);
typedef void*   (*get_dev_handle1)(int);

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class reg_base_info
{
public:
    int arrno;
    int clusterno;
    int devno;
    string dev_type;
    void* dlHandle;

    reg_base_info()
    {

    }

    reg_base_info(const reg_base_info& other) {
        arrno = other.arrno;
        clusterno = other.clusterno;
        devno = other.devno;
        dev_type = other.dev_type;
        dlHandle = other.dlHandle;
    }

    reg_base_info& operator=(const reg_base_info& other) {
        if (this != &other) {
            arrno = other.arrno;
            clusterno = other.clusterno;
            devno = other.devno;
            dev_type = other.dev_type;
            dlHandle = other.dlHandle;
        }
        return *this;
    }

    ~reg_base_info() {
        //delete[] static_cast<char*>(dlHandle);
    }
};

class reg_info_base
{
public:
    reg_info_base() {}

    virtual void get_reg_data(int& int_data, float& float_data) = 0;
    virtual void set_reg_data(int int_data, float float_data) = 0;
    virtual int get_addr()  = 0;
    virtual int get_bais()  = 0;
    virtual int get_precision() = 0;
    virtual std::string get_data_type() = 0;
    virtual std::string get_dataapi_type() = 0;
    ~reg_info_base() {}
};

#endif //MODBUS_SERVER_REG_INFO_BASE_H
