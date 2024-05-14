//
// Created by Administrator on 2023/10/25.
//

#ifndef MOBBUS_SERVER_MODBUSSERVER_H
#define MOBBUS_SERVER_MODBUSSERVER_H

#include <modbus/modbus.h>
#include <istream>
#include <string>
#include <vector>

#include "slaveManager.h"
#include "misc.h"

class modbus_server{
private:
    modbus_server();
public:
    ~modbus_server();
private:
    static modbus_server *m_instance;
public:
    static modbus_server* GetInstance()
    {
        if(m_instance == NULL)
        {
            //锁
            if(m_instance == NULL)
            {
                m_instance = new modbus_server();
                static CGarhuishou cl;
            }
            //放锁
        }
        return m_instance;
    }

    class CGarhuishou
    {
    public:
        ~CGarhuishou()
        {
            if (modbus_server::m_instance)
            {
                delete modbus_server::m_instance;
                modbus_server::m_instance = NULL;
            }
        }
    };

public:
    void run(void);
    bool registerSlavemanager(slaveManager* ma)
    {
        this->i_slaveMager = ma;
        return true;
    }

    slaveManager* getSlavemanager(void)
    {
        return this->i_slaveMager;
    }

private:
    bool initModbus(std::string Host_Ip, int port, bool debugging);

private:
    modbus_t* ctx{ nullptr };
    int m_modbusSocket{ -1 };
    bool m_initialized{ false };
    int m_connCount{0};
    slaveManager* i_slaveMager{NULL};
};

#endif //MOBBUS_SERVER_MODBUSSERVER_H