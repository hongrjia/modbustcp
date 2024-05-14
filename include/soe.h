//
// Created by Administrator on 2024/3/18.
//

#ifndef MODBUS_SERVER_SOE_H
#define MODBUS_SERVER_SOE_H
#include <string>
#include "util.h"
#include "misc.h"

#define SOE_BASE_ID (0x55aa)

class soe{
private:
    soe();
private:
    static soe* m_instance;
public:
    ~soe();

    class CGarhuishou  //类中套类，用于释放对象
    {
    public:
        ~CGarhuishou()
        {
            if (soe::m_instance)
            {
                delete soe::m_instance;
                soe::m_instance = NULL;
            }
        }
    };

    static soe* GetInstance()
    {
        if(m_instance == NULL)
        {
            //锁
            if(m_instance == NULL)
            {
                m_instance = new soe();
                static CGarhuishou cl;
            }
            //放锁
        }
        return m_instance;
    }

    int report_event(int arnum, int clunum, int devno, int eventLevel, int eventID, int eventCode, std::string eventMsg);
private:
    int msg_id;
};

#endif //MODBUS_SERVER_SOE_H
