//
// Created by Administrator on 2023/10/26.
//
#include<thread>
#include <sstream>
#include "slavedev.h"
#include "reg_num.h"
#include "reg_info.h"

slavedev::slavedev(json info)
{
    this->paraInit(info);
}

slavedev::~slavedev()
{
    modbus_mapping_free(this->mb_mapping);

    for (auto iregall : reg_list) {
        delete iregall;
    }
    reg_list.clear();
}

uint8_t slavedev::getTab_Input_Bits(int NumBit)
{
    return mb_mapping->tab_input_bits[NumBit - mb_mapping->start_input_bits];
}

bool slavedev::setTab_Input_Bits(int NumBit, uint8_t Value)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
    mb_mapping->tab_input_bits[NumBit - mb_mapping->start_input_bits] = Value;
    return true;
}

bool slavedev::setTab_bits(int NumBit, uint8_t Value)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
    mb_mapping->tab_bits[NumBit - mb_mapping->start_bits] = Value;
    return true;
}

int slavedev::getTab_bits(int NumBit)
{
    return mb_mapping->tab_bits[NumBit - mb_mapping->start_bits];
}

bool slavedev::setInputRegisterValue(int registerStartaddress, float Value)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
    modbus_set_float(Value, &mb_mapping->tab_input_registers[registerStartaddress - mb_mapping->start_input_registers]);
    return true;
}

bool slavedev::setInputRegisterValue(int registerStartaddress, uint16_t Value)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
    uint16_t *pValue = (uint16_t *)&mb_mapping->tab_input_registers[registerStartaddress - mb_mapping->start_input_registers];
    *pValue = Value;
    return true;
}

bool slavedev::setInputRegisterValue(int registerStartaddress, int16_t Value)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
    int16_t *pValue = (int16_t *)&mb_mapping->tab_input_registers[registerStartaddress - mb_mapping->start_input_registers];
    *pValue = Value;
    return true;
}

bool slavedev::setInputRegisterValue(int registerStartaddress, uint32_t Value)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
    uint32_t *pValue = (uint32_t *)&mb_mapping->tab_input_registers[registerStartaddress - mb_mapping->start_input_registers];
    *pValue = Value;
    return true;
}

bool slavedev::setInputRegisterValue(int registerStartaddress, int32_t Value)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
    int32_t *pValue = (int32_t *)&mb_mapping->tab_input_registers[registerStartaddress - mb_mapping->start_input_registers];
    *pValue = Value;
    return true;
}

bool slavedev::setInputRegisterValueF2I(int addr, float val, string regDataType)
{
    if (regDataType == "float"){
        setInputRegisterValue(addr, val);
    }
    else if (regDataType == "uint16_t")
    {
        uint16_t tmp = std::round(val);
        setInputRegisterValue(addr, tmp);
    }
    else if (regDataType == "int16_t")
    {
        int16_t tmp = std::round(val);
        setInputRegisterValue(addr, tmp);
    }
    else if (regDataType == "int32_t")
    {
        int32_t tmp = std::round(val);
        setInputRegisterValue(addr, tmp);
    }
    else if (regDataType == "uint32_t")
    {
        uint32_t tmp = std::round(val);
        setInputRegisterValue(addr, tmp);
    }
    return true;
}

float slavedev::getHoldingRegisterFloatValue(int registerStartaddress)
{
    return modbus_get_float_badc(&mb_mapping->tab_registers[registerStartaddress - mb_mapping->start_registers]);
}

uint16_t slavedev::getHoldingRegisterValue(int registerStartaddress, uint16_t& value)
{
    uint16_t *pValue = (uint16_t *)&mb_mapping->tab_registers[registerStartaddress - mb_mapping->start_registers];
    value = *pValue;
    return *pValue;
}

int16_t slavedev::getHoldingRegisterValue(int registerStartaddress, int16_t& value)
{
    int16_t *pValue = (int16_t *)&mb_mapping->tab_registers[registerStartaddress - mb_mapping->start_registers];
    value = *pValue;
    return *pValue;
}

uint32_t slavedev::getHoldingRegisterValue(int registerStartaddress,uint32_t& value)
{
    uint32_t *pValue = (uint32_t *)&mb_mapping->tab_registers[registerStartaddress - mb_mapping->start_registers];
    value = *pValue;
    return *pValue;
}

int32_t slavedev::getHoldingRegisterValue(int registerStartaddress, int32_t& value)
{
    int32_t *pValue = (int32_t *)&mb_mapping->tab_registers[registerStartaddress - mb_mapping->start_registers];
    value = *pValue;
    return *pValue;
}

bool slavedev::setHoldingRegisterValue(int registerStartaddress, uint16_t Value)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
    uint16_t *pValue = (uint16_t *)&mb_mapping->tab_registers[registerStartaddress - mb_mapping->start_registers];
    *pValue = Value;
    return true;
}

bool slavedev::setHoldingRegisterValue(int registerStartaddress, int16_t Value)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
    int16_t *pValue = (int16_t *)&mb_mapping->tab_registers[registerStartaddress - mb_mapping->start_registers];
    *pValue = Value;
    return true;
}

bool slavedev::setHoldingRegisterValue(int registerStartaddress, uint32_t Value)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
    uint32_t *pValue = (uint32_t *)&mb_mapping->tab_registers[registerStartaddress - mb_mapping->start_registers];
    *pValue = Value;
    return true;
}

bool slavedev::setHoldingRegisterValue(int registerStartaddress, int32_t Value)
{
    std::lock_guard<std::mutex> mutex(i_mutex);
    int32_t *pValue = (int32_t *)&mb_mapping->tab_registers[registerStartaddress - mb_mapping->start_registers];
    *pValue = Value;
    return true;
}

bool slavedev::setHoldingRegisterValue(int registerStartaddress, float Value)
{
    /*小端模式*/
    std::lock_guard<std::mutex> mutex(i_mutex);
    modbus_set_float(Value, &mb_mapping->tab_registers[registerStartaddress - mb_mapping->start_registers]);
    return true;
}

bool slavedev::setHoldingRegisterValueF2I(int addr, float val, string regDataType)
{
    if (regDataType == "float"){
        setHoldingRegisterValue(addr, val);
    }
    else if (regDataType == "uint16_t")
    {
        uint16_t tmp = std::round(val);
        setHoldingRegisterValue(addr, tmp);
    }
    else if (regDataType == "int16_t")
    {
        int16_t tmp = std::round(val);
        setHoldingRegisterValue(addr, tmp);
    }
    else if (regDataType == "int32_t")
    {
        int32_t tmp = std::round(val);
        setHoldingRegisterValue(addr, tmp);
    }
    else if (regDataType == "uint32_t")
    {
        uint32_t tmp = std::round(val);
        setHoldingRegisterValue(addr, tmp);
    }
    return true;
}


void slavedev::updateInputRegInfo(void)
{
    /* 不同辅控设备 */
    for (reg_all* all : reg_list) 
    {
         /* 同一设备不同类型寄存器 */   
        for (auto reg_info : all->get_input_reg()->get_reg_list()) 
        {
            int int_data = 0;
            float float_data = 0;
            reg_info->get_reg_data(int_data, float_data);

            if ("float" == reg_info->get_dataapi_type())
            {
                float tmp_dat = float_data * reg_info->get_precision() + reg_info->get_bais();
                setInputRegisterValueF2I(reg_info->get_addr(), tmp_dat, reg_info->get_data_type());
            }

            if ("int" == reg_info->get_dataapi_type())
            {
                int tmp_dat = int_data * reg_info->get_precision() + reg_info->get_bais();

                if ("uint16_t" == reg_info->get_data_type())
                {
                    uint16_t uint16_value = static_cast<uint16_t>(tmp_dat);
                    setInputRegisterValue(reg_info->get_addr(), uint16_value);
                }

                if ("int16_t" == reg_info->get_data_type())
                {
                    int16_t int16_value = static_cast<int16_t>(tmp_dat);
                    setInputRegisterValue(reg_info->get_addr(), int16_value);
                }

                if ("uint32_t" == reg_info->get_data_type())
                {
                    uint32_t uint32_value = static_cast<uint32_t>(tmp_dat);
                    setInputRegisterValue(reg_info->get_addr(), uint32_value);
                }

                if ("int32_t" == reg_info->get_data_type())
                {
                    int32_t int32_value = static_cast<int32_t>(tmp_dat);
                    setInputRegisterValue(reg_info->get_addr(), int32_value);
                }
            }
        }
    }
}

void slavedev::updateHoldRegInfo(void)
{
    /* 不同辅控设备 */
    for (reg_all* all : reg_list) 
    {
         /* 同一设备不同类型寄存器 */   
        for (auto reg_info : all->get_hold_reg()->get_reg_list()) 
        {
            int int_data = 0;
            float float_data = 0;
            reg_info->get_reg_data(int_data, float_data);

            if ("float" == reg_info->get_dataapi_type())
            {
                float tmp_dat = float_data * reg_info->get_precision() + reg_info->get_bais();
                setHoldingRegisterValueF2I(reg_info->get_addr(), tmp_dat, reg_info->get_data_type());
            }

            if ("int" == reg_info->get_dataapi_type())
            {
                int tmp_dat = int_data * reg_info->get_precision() + reg_info->get_bais();
                
                if ("uint16_t" == reg_info->get_data_type())
                {
                    uint16_t uint16_value = static_cast<uint16_t>(tmp_dat);
                    setHoldingRegisterValue(reg_info->get_addr(), uint16_value);
                }

                if ("int16_t" == reg_info->get_data_type())
                {
                    int16_t int16_value = static_cast<int16_t>(tmp_dat);
                    setHoldingRegisterValue(reg_info->get_addr(), int16_value);
                }

                if ("uint32_t" == reg_info->get_data_type())
                {
                    uint32_t uint32_value = static_cast<uint32_t>(tmp_dat);
                    setHoldingRegisterValue(reg_info->get_addr(), uint32_value);
                }

                if ("int32_t" == reg_info->get_data_type())
                {
                    int32_t int32_value = static_cast<int32_t>(tmp_dat);
                    setHoldingRegisterValue(reg_info->get_addr(), int32_value);
                }
            }
        }
    }
}

void slavedev::updatediscreteInputRegInfo(void)
{
    /* 不同辅控设备 */
    for (reg_all* all : reg_list) 
    {
         /* 同一设备不同类型寄存器 */   
        for (auto reg_info : all->get_dis_input_reg()->get_reg_list()) 
        {
            int int_data = 0;
            float float_data = 0;
            reg_info->get_reg_data(int_data, float_data);

            if ("float" == reg_info->get_dataapi_type())
            {
                int tmp_dat = float_data * reg_info->get_precision() + reg_info->get_bais();               
                uint8_t uint8_value = static_cast<uint8_t>(tmp_dat);
                setTab_Input_Bits(reg_info->get_addr(), uint8_value);            
            }

            if ("int" == reg_info->get_dataapi_type())
            {
                int tmp_dat = int_data * reg_info->get_precision() + reg_info->get_bais();               
                uint8_t uint8_value = static_cast<uint8_t>(tmp_dat);
                setTab_Input_Bits(reg_info->get_addr(), uint8_value);
            }
        }
    }
}

void slavedev::updatecoilRegInfo(void)
{
    for (reg_all* all : reg_list) 
    {
         /* 同一设备不同类型寄存器 */   
        for (auto reg_info : all->get_coil_reg()->get_reg_list()) 
        {
            int int_data = 0;
            float float_data = 0;
            reg_info->get_reg_data(int_data, float_data);

            if ("float" == reg_info->get_dataapi_type())
            {
                int tmp_dat = float_data * reg_info->get_precision() + reg_info->get_bais();
                uint8_t uint8_value = static_cast<uint8_t>(tmp_dat);
                setTab_bits(reg_info->get_addr(), uint8_value);            
            }

            if ("int" == reg_info->get_dataapi_type())
            {
                int tmp_dat = int_data * reg_info->get_precision() + reg_info->get_bais();
                uint8_t uint8_value = static_cast<uint8_t>(tmp_dat);
                setTab_bits(reg_info->get_addr(), uint8_value);
            }
        }
    }
}

void* slavedev::readMem2regTask(void)
{
    int startFlag = true;
    while (startFlag)
    {
        devMiscWork();

        // 更新输入寄存器数量
        updateInputRegInfo();

        // 更新输入线圈
        updatediscreteInputRegInfo();

        // 更新保持寄存器
        updateHoldRegInfo();

        // 更新线圈
        updatecoilRegInfo();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void* slavedev::updateReg2MemTask(void)
{
    int startFlag = true;
    while (startFlag)
    {
        auto msg = i_msgQueue.receiveMsg();
        if (msg != nullptr)
        {
//            std::cout << "onMessage ..." <<std::endl;
            onMessage(msg);
        }
    }
}

bool slavedev::writeSigHoldReg(std::shared_ptr<msg> &msg)
{
    /* 不同辅控设备 */
    int find_flag = 0; 
    int addr = msg->iaddr;
    for (reg_all* all : reg_list) 
    {
        if (1 == find_flag)
        {
            break;
        }

         /* 同一设备不同类型寄存器 */   
        for (auto reg_info : all->get_hold_reg()->get_reg_list()) 
        {
            if (addr == reg_info->get_addr())
            {
                float val_float = 0;
                int val_int = 0;
                if (reg_info->get_data_type() == "uint16_t")
                {
                    uint16_t tmp = 0;
                    getHoldingRegisterValue(addr, tmp);
                    val_int = (tmp - reg_info->get_bais()) / reg_info->get_precision();
                    val_float = (tmp - reg_info->get_bais())*1.0  / reg_info->get_precision();
                    reg_info->set_reg_data(val_int, val_float);
                }
                else if (reg_info->get_data_type()  == "int16_t")
                {
                    int16_t tmp = 0;
                    getHoldingRegisterValue(addr, tmp);
                    val_int = (tmp - reg_info->get_bais()) / reg_info->get_precision();
                    val_float = (tmp - reg_info->get_bais())*1.0 / reg_info->get_precision();
                    reg_info->set_reg_data(val_int, val_float);
                }
                else if (reg_info->get_data_type()  == "int32_t")
                {
                    int32_t tmp = 0;
                    getHoldingRegisterValue(addr, tmp);
                    val_int = (tmp - reg_info->get_bais()) / reg_info->get_precision();
                    val_float = (tmp - reg_info->get_bais())*1.0  / reg_info->get_precision();
                    reg_info->set_reg_data(val_int, val_float);
                }
                else if (reg_info->get_data_type()  == "uint32_t")
                {
                    uint32_t tmp = 0;
                    getHoldingRegisterValue(addr, tmp);
                    val_int = (tmp - reg_info->get_bais()) / reg_info->get_precision();
                    val_float = (tmp - reg_info->get_bais())*1.0  / reg_info->get_precision();
                    reg_info->set_reg_data(val_int, val_float);
                }
                else if (reg_info->get_data_type()  == "float_t")
                {
                    val_float = getHoldingRegisterFloatValue(addr);
                    val_float = (val_float - reg_info->get_bais()) / reg_info->get_precision();
                    val_int = val_float;
                    reg_info->set_reg_data(val_int, val_float);
                }
                else
                {
                    std::cout << "unkonw type err !!!!!" << reg_info->get_data_type() << std::endl;
                }

                find_flag = 1;
                break;
            }
        }
    }
    return true;
}

bool slavedev::writeMulHoldReg(std::shared_ptr<msg> &msg)
{
    int addr = msg->iaddr;
    int nr = msg->inr;
    int addr_add_val = 0;
    for (int k  = 0; k < nr; k++)
    {
        int find_flag = 0; 
        for (reg_all* all : reg_list) 
        {
            if (1 == find_flag)
            {
                break;
            }

            /* 同一设备不同类型寄存器 */   
            for (auto reg_info : all->get_hold_reg()->get_reg_list()) 
            {
                if (addr == reg_info->get_addr())
                {
                    float val_float = 0;
                    int val_int = 0;
                    if (reg_info->get_data_type() == "uint16_t")
                    {
                        uint16_t tmp = 0;
                        getHoldingRegisterValue(addr, tmp);
                        val_int = (tmp - reg_info->get_bais()) / reg_info->get_precision();
                        val_float = (tmp - reg_info->get_bais())*1.0  / reg_info->get_precision();
                        reg_info->set_reg_data(val_int, val_float);
                        addr_add_val = 1;
                    }
                    else if (reg_info->get_data_type()  == "int16_t")
                    {
                        int16_t tmp = 0;
                        getHoldingRegisterValue(addr, tmp);
                        val_int = (tmp - reg_info->get_bais()) / reg_info->get_precision();
                        val_float = (tmp - reg_info->get_bais()) * 1.0 / reg_info->get_precision();
                        reg_info->set_reg_data(val_int, val_float);
                        addr_add_val = 1;
                    }
                    else if (reg_info->get_data_type()  == "int32_t")
                    {
                        int32_t tmp = 0;
                        getHoldingRegisterValue(addr, tmp);
                        val_int = (tmp - reg_info->get_bais()) / reg_info->get_precision();
                        val_float = (tmp - reg_info->get_bais())*1.0  / reg_info->get_precision();
                        reg_info->set_reg_data(val_int, val_float);
                        addr_add_val = 2;
                    }
                    else if (reg_info->get_data_type()  == "uint32_t")
                    {
                        uint32_t tmp = 0;
                        getHoldingRegisterValue(addr, tmp);
                        val_int = (tmp - reg_info->get_bais()) / reg_info->get_precision();
                        val_float = (tmp - reg_info->get_bais())*1.0  / reg_info->get_precision();
                        reg_info->set_reg_data(val_int, val_float);
                        addr_add_val = 2;
                    }
                    else if (reg_info->get_data_type()  == "float")
                    {
                        val_float = getHoldingRegisterFloatValue(addr);
                        val_float = (val_float - reg_info->get_bais()) / reg_info->get_precision();
                        val_int = val_float;
                        reg_info->set_reg_data(val_int, val_float);
                        addr_add_val = 2;
                    }
                    else
                    {
                        std::cout << "unkonw type err !!!!!" << reg_info->get_data_type() << std::endl;
                    }

                    find_flag = 1;
                    break;
                }
            }
        }
        addr += addr_add_val;
    }
    return true;
}

bool slavedev::writeSingCoilReg(std::shared_ptr<msg> &msg)
{
    int addr = msg->iaddr;
    int find_flag = 0; 
    for (reg_all* all : reg_list) 
    {
        if (1 == find_flag)
        {
            break;
        }
   
        for (auto reg_info : all->get_hold_reg()->get_reg_list()) 
        {
            if (addr == reg_info->get_addr())
            {
                float val_float = 0;
                int val_int = 0;
                if (reg_info->get_data_type() == "uint16")
                {
                    uint16_t tmp = 0;
                    tmp = getTab_bits(addr);
                    val_int = tmp;
                    val_int = (val_int - reg_info->get_bais()) / reg_info->get_precision();
                    reg_info->set_reg_data(val_int, val_float);
                }
                else
                {
                    std::cout << "unkonw type err !!!!!" << reg_info->get_data_type() << std::endl;
                }
                
                find_flag = 1;
                break;
            }
        }
    }
    return true;
}

bool slavedev::writeMulCoilReg(std::shared_ptr<msg> &msg)
{
    int addr = msg->iaddr;
    int nr = msg->inr;
    for (int k  = 0; k < nr; k++)
    {
        int find_flag = 0;
        for (reg_all* all : reg_list) 
        {
            if (1 == find_flag)
            {
                break;
            }

            /* 同一设备不同类型寄存器 */   
            for (auto reg_info : all->get_hold_reg()->get_reg_list()) 
            {
                if (addr == reg_info->get_addr())
                {
                    float val_float = 0;
                    int val_int = 0;
                    if (reg_info->get_data_type() == "uint16")
                    {
                        uint16_t tmp = 0;
                        tmp = getTab_bits(addr);
                        val_int = tmp;
                        val_int = (val_int - reg_info->get_bais()) / reg_info->get_precision();
                        reg_info->set_reg_data(val_int, val_float);
                    }
                    else
                    {
                        std::cout << "unkonw type err !!!!!" << reg_info->get_data_type() << std::endl;
                    }
                    
                    find_flag = 1;
                    break;
                }
            }
        }
        addr += 1;
    }
    return true;
}

void slavedev::onMessage(std::shared_ptr<msg> &msg)
{
    // TODO: 先把功能实现吧 后续在优化
    /* 0x06 命令码可以对保持寄存器进行读写 */
    if (0x06 == msg->ifunId)
    {
        writeSigHoldReg(msg);
    }

    /* 写多个保持寄存器：16（10H） */
    if (0x10 == msg->ifunId)
    {
        writeMulHoldReg(msg);
    }

    /* 写单个线圈 */
    if (0x05 == msg->ifunId)
    {
        writeSingCoilReg(msg);
    }

    /* 写多个线圈 */
    if (0x0f == msg->ifunId)
    {
        writeMulCoilReg(msg);
    }
}

void slavedev::paraInit(json info) {
    slaveId = info["slave_id"];
    dzlog_info("slave_id ****** %d", slaveId);
    reg_all* iregall = new reg_all(info);
    reg_list.push_back(iregall);
}

/* 当找到同一 slave id 的时候，更新新增寄存器内容 */
void slavedev::updateReg(json info)
{
    dzlog_info("updateReg");
    reg_all* iregall = new reg_all(info);
    reg_list.push_back(iregall);
}

bool slavedev::start()
{
    /**
     * 1.统计寄存器数量
     * 2.最大最小地址
     * */
    mis_work_before_start();
    printMessageInfo();

    //读取内存到寄存器
    myThread_1 = std::thread(&slavedev::readMem2regTask, this);
    myThread_1.detach();

    //更新寄存器信息到内存
    myThread_2 = std::thread(&slavedev::updateReg2MemTask,this);
    myThread_2.detach();
}

int slavedev::get_min_addr(int addr1, int addr2)
{
    if ((addr1 > 0) && (addr2 > 0))
    {
        if (addr1 > addr2)
        {
            return addr2;
        }
        else
        {
            return addr1;
        }
    } 
    else if ((addr1 < 0) && (addr2 < 0))
    {
        return -1;
    }
    else if (addr1 > 0)
    {
        return addr1;
    }
    else if (addr2 > 0)
    {
        return addr2;
    }
    else
    {
        std::cout << "get_min_addr can get here ???? !!!!!\n";
    }
}

int slavedev::get_max_addr(int addr1, int addr2)
{
    if ((addr1 > 0) && (addr2 > 0))
    {
        if (addr1 > addr2)
        {
            return addr1;
        }
        else
        {
            return addr2;
        }
    } 
    else if ((addr1 < 0) && (addr2 < 0))
    {
        return -1;
    }
    else if (addr1 > 0)
    {
        return addr1;
    }
    else if (addr2 > 0)
    {
        return addr2;
    }
    else
    {
        std::cout << "get_max_addr can get here ???? !!!!!\n";
    }
}

bool slavedev::mis_work_before_start(void)
{
    /* 1. 统计当前设备各个寄存器的数量 */
    /* 2. 找出当前类型寄存器最小和最大的地址 */
    int input_cnt = 0;
    int coil_cnt = 0;
    int hold_cnt = 0;
    int dis_input = 0;

    if (!reg_list.empty()) 
    {
        reg_all* firstElement = reg_list.front();
        firstElement->get_min_max_addr(input_min_addr, input_max_addr,
                                       coil_min_addr, coil_max_addr,
                                       hold_min_addr, hold_max_addr,
                                       input_dis_min_addr, input_dis_max_addr);
    }
    else
    {
        std::cout << "The list is empty." << std::endl;
    }

    for (auto iregall : reg_list) 
    {
        int count = 0;
        /* 输入寄存器 */
        int tmp_input_min_addr = -1;
        int tmp_input_max_addr = -1;

        /* 线圈 */
        int tmp_coil_min_addr = -1;
        int tmp_coil_max_addr = -1;

        /* 保持寄存器 */
        int tmp_hold_min_addr = -1;
        int tmp_hold_max_addr = -1;

        /* 离散输入 */
        int tmp_input_dis_min_addr = -1;
        int tmp_input_dis_max_addr = -1;

        iregall->get_min_max_addr(tmp_input_min_addr, tmp_input_max_addr,
                                tmp_coil_min_addr, tmp_coil_max_addr,
                                tmp_hold_min_addr, tmp_hold_max_addr,
                                tmp_input_dis_min_addr, tmp_input_dis_max_addr);

#if 0
        std::cout << __FILE__ << ":" << __LINE__ << std::endl;
        std::cout << " " << tmp_coil_min_addr << " " << tmp_coil_max_addr << std::endl   
                << " " << tmp_input_dis_min_addr << " " << tmp_input_dis_max_addr << std::endl
                << " " << tmp_hold_min_addr << " " << tmp_hold_max_addr << std::endl
                << " " << tmp_input_min_addr << " " << tmp_input_max_addr << std::endl;                  
#endif

        input_min_addr = get_min_addr(input_min_addr, tmp_input_min_addr);
        input_max_addr = get_max_addr(input_max_addr, tmp_input_max_addr);

        coil_min_addr = get_min_addr(coil_min_addr, tmp_coil_min_addr);
        coil_max_addr = get_max_addr(coil_max_addr, tmp_coil_max_addr);

        hold_min_addr = get_min_addr(hold_min_addr, tmp_hold_min_addr);
        hold_max_addr = get_max_addr(hold_max_addr, tmp_hold_max_addr);

        input_dis_min_addr = get_min_addr(input_dis_min_addr, tmp_input_dis_min_addr);
        input_dis_max_addr = get_max_addr(input_dis_max_addr, tmp_input_dis_max_addr);
    }

    if (-1 == input_min_addr)
    {
        input_min_addr = input_max_addr = 0;
    }

    if (-1 == coil_min_addr)
    {
        coil_min_addr = coil_max_addr = 0;
    }

    if (-1 == hold_min_addr)
    {
        hold_min_addr = hold_max_addr = 0;
    }

    if (-1 == input_dis_min_addr)
    {
        input_dis_min_addr = input_dis_max_addr = 0;
    }

    modbus_mapping_t* pmb_mapping = NULL;
    pmb_mapping = modbus_mapping_new_start_address(coil_min_addr, coil_max_addr - coil_min_addr + 1, 
                                                    input_dis_min_addr, input_dis_max_addr - input_dis_min_addr + 1,
                                                    hold_min_addr, hold_max_addr - hold_min_addr + 1, 
                                                    input_min_addr, input_max_addr - input_min_addr + 1);
    if (NULL != pmb_mapping)
    {
        mb_mapping = pmb_mapping;
    }
    else
    {
        dzlog_error("modbus map create err");
    }
    return true;
}

void slavedev::printMessageInfo(void)
{
    dzlog_info("current dev slave id = %d", slaveId);
    dzlog_info("reg_list.size  = %d", reg_list.size());

    for (auto iregall : reg_list) 
    {
        iregall->printInfo();
        std::cout << "-------------------------------------------------------------" << std::endl;
    }

    std::stringstream ss;
    ss << "********************************************************************" << std::endl;
    ss << "all coil info :" << std::to_string(coil_min_addr) << "  "<< std::to_string(coil_max_addr)  << std::endl;
    ss << "all input_dis info :" << std::to_string(input_dis_min_addr) << "  " << std::to_string(input_dis_max_addr)  << std::endl;
    ss << "all hold info :" << std::to_string(hold_min_addr) << "  " << std::to_string(hold_max_addr) << std::endl;
    ss << "all input info :" << std::to_string(input_min_addr) << "  " << std::to_string(input_max_addr) << std::endl;
    dzlog_info("%s", ss.str().c_str());
}
