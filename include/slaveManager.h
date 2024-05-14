//
// Created by Administrator on 2023/10/27.
//
#ifndef MOBBUS_SERVER_SLAVEMANAGER_H
#define MOBBUS_SERVER_SLAVEMANAGER_H

#include<list>
#include<iostream>
#include <cstring>
#include <dirent.h>
#include <vector>
#include "slavedev.h"
#include "misc.h"

using namespace std;




class slaveManager{

private:
    slaveManager()
    {
    }
    slaveManager(const slaveManager& obj);
    bool construct();
public:

    /**
     * @brief  根据slaveID查找对应slavedev
     * @param [in] slaveId 从机id
     * */
    slavedev* findSlave(int slaveId);
    void devStartWork(void);
    void printMessageInfo(void);
public:
    static slaveManager* NewInstance();

private:
    int slaveNum{0};            // slave 从机个数
    list<slavedev*> devList;   // 存放 slave 从机的列表
};

#endif //MOBBUS_SERVER_SLAVEMANAGER_H