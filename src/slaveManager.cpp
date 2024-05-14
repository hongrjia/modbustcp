//
// Created by Administrator on 2023/10/27.
//
#include <string>
#include "slaveManager.h"
#include "jsonparser.h"
#include "json.hpp"
#include "slavedev.h"
#include "util.h"
#include "cconfig.h"

using namespace nlohmann;



bool slaveManager::construct()
{
    bool ret = false;
    std::string currentPath = cconfig::GetInstance()->GetString("config_path");
    std::vector<std::string> jsonFiles = cconfig::GetInstance()->getAllJsonFiles(currentPath);
    if (jsonFiles.empty())
    {
        dzlog_error("No JSON files found in the current directory");
        return ret;
    }
    else
    {
        dzlog_info("JSON files in the current directory:");
        for (const auto& filename : jsonFiles)
        {
            std::string ifile = currentPath + filename;
            dzlog_info("%s", ifile.c_str());

            //获取json里的内容
            json* pjson = jsonParser::GetInstance()->get(ifile);

            dzlog_info("Ver: %s", (*pjson)["fmtVer"]);
            dzlog_info("serviceId: %s", (*pjson)["serviceId"]);

            json slaveInfoJson = (*pjson)["slave_info"][0];
            dzlog_info("filename  %s,   slave id  %d" , filename.c_str(), slaveInfoJson["slave_id"]);

            slavedev* idev = findSlave(slaveInfoJson["slave_id"]);
            if (idev != NULL)
            {
                // 设备存在更新数据
                dzlog_info("当前设备 id 存在");
                //更新寄存器信息
                idev->updateReg(slaveInfoJson);
            }
            else
            {
                // 创建不存在的新设备
                class devFactory factory;
                dzlog_info("当前设备 id 不存在，需要创建设备...");
                slavedev* dev = factory.createDev("all_dev", slaveInfoJson);
                if (dev)
                {
                    dzlog_info("create a slave dev id %d success   ~~~", slaveInfoJson["slave_id"]);
                    this->devList.push_back(dev);
                }
                else
                {
                    dzlog_info("create a slave dev id %d failed   ~~~", slaveInfoJson["slave_id"]);
                    return false;
                }
            }
        }
    }

    ret = true;
    return ret;
}

slaveManager* slaveManager::NewInstance()
{
    slaveManager* ret = new slaveManager();
    if( !(ret && ret->construct()) )
    {
        delete ret;
        ret = NULL;
    }
    return ret;
}

slavedev* slaveManager::findSlave(int slaveId)
{
    for (auto& dev : devList) {
        int id = dev->getSlaveId();
        if (id == slaveId)
        {
            return  dev;
        }
    }
    return NULL;
}

void slaveManager::devStartWork(void)
{
    for (auto& dev : devList) 
    {
        dev->start();
    }
    printMessageInfo();
}

void slaveManager::printMessageInfo(void)
{
    dzlog_info("slaveManager device Info : \n devnum:  %d ", devList.size());
    dzlog_info("****************************************************************");
    for (auto& dev : devList) 
    {
        dev->printMessageInfo();
    }
}