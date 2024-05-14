//
// Created by Administrator on 2023/10/25.
//

#ifndef MOBBUS_SERVER_CCONFIG_H
#define MOBBUS_SERVER_CCONFIG_H
#include <vector>
#include <string>
#include "util.h"
#include "misc.h"


/**
 * @brief 加载配置文件类
 * */
class cconfig {
private:
    cconfig();
public:
    ~cconfig();
private:
    static cconfig *m_instance;

public:
    static cconfig* GetInstance()
    {
        if(m_instance == NULL)
        {
            //加锁
            if(m_instance == NULL)
            {
                m_instance = new cconfig();
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
            if (cconfig::m_instance)
            {
                delete cconfig::m_instance;
                cconfig::m_instance = NULL;
            }
        }
    };
public:

    /**
     * @brief 加载modbus.conf配置文件
     * @param [in] pconfName 配置文件名
     * */
    bool Load(const char *pconfName); //装载配置文件

    /**
     * @brief 获取配置文件中的ItemContent
     * @param [in] p_itemname 读取的配置key
     * */
    const char *GetString(const char *p_itemname);
    int  GetIntDefault(const char *p_itemname,const int def);

    /**
     * @brief 获取config路径下的所有json文件
     * @param [in] path 获取路径
     * */
    std::vector<std::string> getAllJsonFiles(const std::string& path);
public:
    typedef struct _CConfItem
    {
        char ItemName[50];
        char ItemContent[500];
    }CConfItem,*LPCConfItem;

public:
    std::vector<LPCConfItem> m_ConfigItemList; //存储配置信息的列表
};


#endif //MOBBUS_SERVER_CCONFIG_H
