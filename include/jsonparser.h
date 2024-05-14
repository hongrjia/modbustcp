//
// Created by Administrator on 2023/10/26.
//

#ifndef MOBBUS_SERVER_JSONPARSER_H
#define MOBBUS_SERVER_JSONPARSER_H
#include <fstream>
#include <iostream>
#include <unordered_map>
#include "json.hpp"
#include "misc.h"
using namespace nlohmann;
using namespace std;


/**
 * @brief json解析
 * */
class jsonParser {
private:
    jsonParser();
public:
    ~jsonParser();
private:
    static jsonParser *m_instance;

public:
    static jsonParser* GetInstance()
    {
        if(m_instance == NULL)
        {
            //锁
            if(m_instance == NULL)
            {
                m_instance = new jsonParser();
                static CGarhuishou cl;
            }
            //放锁
        }
        return m_instance;
    }
    class CGarhuishou  //类中套类，用于释放对象
    {
    public:
        ~CGarhuishou()
        {
            if (jsonParser::m_instance)
            {
                delete jsonParser::m_instance;
                jsonParser::m_instance = NULL;
            }
        }
    };
//---------------------------------------------------
public:

    /**
     * @brief 获取json的内容
     * @param [in] key
     * */
    json* get(std::string key)
    {
        dzlog_info("key = %s", key.c_str());
        return modbus_map[key];
    }

    bool load(const char *jsonfile);
private:
//    json* m_modbusJson;
    std::unordered_map<std::string, json*> modbus_map;
};


#endif //MOBBUS_SERVER_JSONPARSER_H
