//
// Created by Administrator on 2024/3/18.
//

#include "../include/soe.h"
#include <iostream>

extern "C"{
#include "event_data.h"
}

soe *soe::m_instance = NULL;

soe::soe()
{
    std::string dev_type = "MODBUS";
    std::string dev_tag = "modbus控制";
    msg_id = event_init(const_cast<char*>(dev_type.data()), const_cast<char*>(dev_tag.data()), 0);
    if (msg_id < 0)
    {
        msg_id = -1;
        dzlog_error("msg_id err");
    }
}

int soe::report_event(int arnum, int clunum, int devno, int eventLevel, int eventID, int eventCode, std::string eventMsg)
{
    std::string dev_type = "MODBUS";
    return event_send(eventLevel, const_cast<char*>(dev_type.data()), devno, eventID, eventCode, const_cast<char*>(eventMsg.data()), arnum, clunum, -1);
}

soe::~soe()
{

}
