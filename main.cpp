#include <iostream>
#include "cconfig.h"
#include "modbusServer.h"
#include "jsonparser.h"
#include "json.hpp"
#include "slavedev.h"
#include "slaveManager.h"
#include "misc.h"
#include "util.h"

using namespace std;
using namespace nlohmann;

int main(int argc, char* argv[])
{
    if (-1 == IsProcessRunning())
    {
        printf("init process error\n");
        return -1;
    }

    if(-1 == InitLog())
    {   //初始化日志系统
        printf("init log error\n");
        return -1;
    }

    gitVer();

    cconfig *p_config = cconfig::GetInstance();
    if (false == p_config->Load("modbus.conf"))
    {
        dzlog_error("load conf file failed ");
        return -1;
    }

    jsonParser *parser = jsonParser::GetInstance();
    if (NULL != parser)
    {
        std::string currentPath = p_config->GetString("config_path"); // ./config/
        if (currentPath.empty())
        {
            dzlog_error("config_path get err!!!!");
            return -1;
        }

        //jsonFiles记录config路径下所有json的名称
        std::vector<std::string> jsonFiles = p_config->getAllJsonFiles(currentPath);
        for (const auto& filename : jsonFiles)
        {
            std::string ifile = currentPath + filename;
            if (false == parser->load(ifile.c_str()))
            {
                dzlog_error("create jsonParser err %s", filename.c_str());
                return -1;
            }
        }
    }

    /* modbus 相关初始化 */
    slaveManager* manager =  slaveManager::NewInstance();
    if (manager)
    {
        manager->devStartWork();
        mic_task_init();
        modbus_server* p_modbus_svr = modbus_server::GetInstance();
        if (p_modbus_svr)
        {
            p_modbus_svr->registerSlavemanager(manager);
            mic_modbus_task();
            p_modbus_svr->run();
        }
        else
        {
            dzlog_error("modbus_server::GetInstance() err");
            return -1;
        }
    }
    else
    {
        dzlog_error( "slaveManager::NewInstance() err");
        return -1;
    }

    dzlog_error("exit modbusServer");
    return 0;
}