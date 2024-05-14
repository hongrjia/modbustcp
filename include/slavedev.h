//
// Created by Administrator on 2023/10/26.
//
#ifndef MOBBUS_SERVER_SLAVEDEV_H
#define MOBBUS_SERVER_SLAVEDEV_H

#include <list>
#include <thread>
#include <mutex>
#include <memory>
#include <modbus/modbus.h>
#include "json.hpp"
#include "jsonparser.h"
#include "messageQueue.h"
#include "reg_all.h"
#include "misc.h"

using namespace nlohmann;
using namespace std;

class msg{
public:
    int iaddr{-1};
    int ifunId{-1};
    int inr{-1};
public:
    msg(int addr, int funcId, int regNr)
    {
        iaddr = addr;
        ifunId = funcId;
        inr = regNr;
    }
    ~msg()
    {

    }
};

class slavedev{
public:
    slavedev(json info);
    ~slavedev();

    int getSlaveId()
    {
        return this->slaveId;
    }
    void setModbusMap(modbus_mapping_t* mp)
    {
        this->mb_mapping = mp;
    }
    modbus_mapping_t* getModbusMap(void)
    {
        return this->mb_mapping;
    }

protected:
    virtual void devMiscWork(){};

private:
    void onMessage(std::shared_ptr<msg> &sendmsg);

public:
    bool sedMsg2Queue(std::shared_ptr<msg> const &sendMsg)
    {
        i_msgQueue.sendMessage(sendMsg);
    }

private:
    void paraInit(json info);

private:
    void updateInputRegInfo(void);
    void updateHoldRegInfo(void);
    void updatediscreteInputRegInfo(void);
    void updatecoilRegInfo(void);
    void* readMem2regTask(void);
    void* updateReg2MemTask(void);

public:
    uint8_t getTab_Input_Bits(int NumBit);
    bool setTab_Input_Bits(int NumBit, uint8_t Value);
    /* 保持寄存器 */
    uint16_t getHoldingRegisterValue(int registerNumber);
    float getHoldingRegisterFloatValue(int registerStartaddress);
    uint16_t getHoldingRegisterValue(int registerStartaddress, uint16_t& val);
    int16_t getHoldingRegisterValue(int registerStartaddress, int16_t& val);
    uint32_t getHoldingRegisterValue(int registerStartaddress, uint32_t& val);
    int32_t getHoldingRegisterValue(int registerStartaddress, int32_t& val);
    bool setHoldingRegisterValue(int registerNumber, uint16_t Value);
    bool setHoldingRegisterValue(int registerNumber, float Value);
    bool setHoldingRegisterValue(int registerStartaddress, int16_t Value);
    bool setHoldingRegisterValue(int registerStartaddress, uint32_t Value);
    bool setHoldingRegisterValue(int registerStartaddress, int32_t Value);
    bool setHoldingRegisterValueF2I(int registerNumber, float Value, string type);
    /* 输入寄存器 */
    bool setInputRegisterValue(int registerNumber, uint16_t Value);
    bool setInputRegisterValue(int registerNumber, int16_t Value);
    bool setInputRegisterValue(int registerNumber, uint32_t Value);
    bool setInputRegisterValue(int registerNumber, int32_t Value);
    bool setInputRegisterValue(int registerNumber, float Value);
    bool setInputRegisterValueF2I(int registerNumber, float Value, string type);
    bool setTab_bits(int NumBit, uint8_t Value);
    int getTab_bits(int NumBit);
    bool writeMulCoilReg(std::shared_ptr<msg> &msg);
    bool writeSingCoilReg(std::shared_ptr<msg> &msg);
    bool writeMulHoldReg(std::shared_ptr<msg> &msg);
    bool writeSigHoldReg(std::shared_ptr<msg> &msg);
    int get_max_addr(int addr1, int addr2);
    int get_min_addr(int addr1, int addr2);

public:
    void updateReg(json info);
    bool mis_work_before_start(void);
    bool start(void);
    void printMessageInfo(void);

private:
    int slaveId;                    // 从机地址
    modbus_mapping_t* mb_mapping;   // 当前从机对应的寄存器映射

    std::mutex i_mutex;
    std::thread myThread_1;
    std::thread myThread_2;
    messageQueue<msg> i_msgQueue;
    std::list<reg_all*> reg_list;      /* 当前设备寄存按照文件的方式进行组织 */

    /* 输入寄存器 */
    int input_min_addr = 0;
    int input_max_addr = 0;

    /* 线圈 */
    int coil_min_addr = 0;
    int coil_max_addr = 0;

    /* 保持寄存器 */
    int hold_min_addr = 0;
    int hold_max_addr = 0;

    /* 离散输入 */
    int input_dis_min_addr = 0;
    int input_dis_max_addr = 0;

};

class airSlaveDevice : public slavedev
{
public:
    airSlaveDevice(string name, json info):slavedev(info)
    {
        iname = name;
    }
protected:
    void devMiscWork()
    {
        std::cout << iname <<" devMiscWork" << std::endl;
    }
private:
    string iname{""};
};

class pcsSlaveDevice : public slavedev
{
public:
    pcsSlaveDevice(string name, json info):slavedev(info)
    {
        iname = name;
    }
protected:
    void devMiscWork()
    {
        std::cout << iname <<" devMiscWork" << std::endl;
    }
private:
    string iname{""};
};

class meterSlaveDevice : public slavedev
{
public:
    meterSlaveDevice(string name, json info):slavedev(info)
    {
        iname = name;
    }
protected:
    void devMiscWork()
    {
        std::cout << iname <<" devMiscWork" << std::endl;
    }
private:
    string iname{""};
};

class arraySlaveDevice : public slavedev
{
public:
    arraySlaveDevice(string name, json info):slavedev(info)
    {
        iname = name;
    }
protected:
    void devMiscWork()
    {
        std::cout << iname <<" devMiscWork" << std::endl;
    }
private:
    string iname{""};
};

class clusterSlaveDevice : public slavedev
{
public:
    clusterSlaveDevice(string name, json info):slavedev(info)
    {
        iname = name;
    }
protected:
    void devMiscWork()
    {
        std::cout << iname <<" devMiscWork" << std::endl;
    }
private:
    string iname{""};
};

class emsSlaveDevice : public slavedev
{
public:
    emsSlaveDevice(string name, json info):slavedev(info)
    {
        iname = name;
    }
protected:
    void devMiscWork()
    {
        std::cout << iname <<" devMiscWork" << std::endl;
    }
private:
    string iname{""};
};

class devFactory {
public:
    slavedev* createDev(const std::string& devType, json info) const {
        if (devType == "air") {
            return (new airSlaveDevice(devType,info));
        }
        else if (devType == "pcs")
        {
            return (new pcsSlaveDevice(devType, info));
        }
        else if (devType == "meter")
        {
            return (new meterSlaveDevice(devType, info));
        }
        else if (devType == "array")
        {
            return (new arraySlaveDevice(devType, info));
        }
        else if (devType == "cluster")
        {
            return (new clusterSlaveDevice(devType, info));
        }
        else if (devType == "ems_do")
        {
            return (new emsSlaveDevice(devType, info));
        }
        else
        {
            return (new slavedev(info));
        }
    }
};
#endif //MOBBUS_SERVER_SLAVEDEV_H