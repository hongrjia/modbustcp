//
// Created by Administrator on 2023/10/26.
//
#include "json.hpp"
#include "cconfig.h"
#include "jsonparser.h"
//静态成员赋值
jsonParser *jsonParser::m_instance = NULL;

jsonParser::jsonParser()
{
}

bool jsonParser::load(const char *jsonfile)
{
    if (jsonfile)
    {
        ifstream ifs(jsonfile);
        if (!ifs.is_open()) {
            dzlog_error("jsonParser: open file error");
            return false;
        }
        dzlog_info("load %s", jsonfile);
        modbus_map[jsonfile] = new json();
        ifs >> *modbus_map[jsonfile];
        return true;
    }
    return false;
}

jsonParser::~jsonParser()
{
    for (auto& pair : modbus_map) {
        delete pair.second;
    }
    modbus_map.clear();
    return;
}
