//
// Created by Administrator on 2023/10/25.
//

#include <string>
#include <cstdio>
#include <iostream>
#include <memory>
#include <pthread.h>
#include <unistd.h>
#include <error.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include <string.h>
#include "cconfig.h"
#include "modbusServer.h"
#include "slavedev.h"
#include "misc.h"
#include "../include/util.h"


//类静态变量初始化
modbus_server *modbus_server::m_instance = NULL;

modbus_server::modbus_server()
{
    std::string host="0.0.0.0";
    int port = 5020;
    cconfig *p_config = cconfig::GetInstance();
    port = p_config->GetIntDefault("modbusPort", port);
    //std::cout << "get listen port -->" << port << std::endl;
    dzlog_info("get listen port --> %d", port);
    initModbus(host, port, false);
}

modbus_server::~modbus_server()
{
    // TODO: 释放对应的 map 映射
    //  modbus_mapping_free(mapping);
    modbus_close(ctx);
    modbus_free(ctx);
}

bool modbus_server::initModbus(std::string Host_Ip = "127.0.0.1", int port = 502, bool debugging = true)
{
    ctx = modbus_new_tcp(Host_Ip.c_str(), port);
    modbus_set_debug(ctx, debugging);
    if (ctx == NULL)
    {
        dzlog_error("There was an error allocating the modbus\n");
        throw - 1;
    }
    m_modbusSocket = modbus_tcp_listen(ctx, 1);
    if (m_modbusSocket)
    {
        m_initialized = true;
        dzlog_info("modbus listen success ip %s - %d - %d", Host_Ip.c_str(), port, m_modbusSocket);
        return  true;
    }
    else
    {
        dzlog_error("modbus listen success ip err !!!! ");
        exit(-1);
    }
    return false;
}

void modbus_server::run(void)
{
    uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
    int master_socket;
    int rc;
    fd_set refset;
    fd_set rdset;
    /* Maximum file descriptor number */
    int fdmax;
    /* Clear the reference set of socket */
    FD_ZERO(&refset);
    /* Add the server socket */
    FD_SET(m_modbusSocket, &refset);

    /* Keep track of the max file descriptor */
    fdmax = m_modbusSocket;

    while( true )
    {
        rdset = refset;
        if (select(fdmax+1, &rdset, NULL, NULL, NULL) == -1)
        {
            perror("Server select() failure.");
            break;
        }
        /* Run through the existing connections looking for data to be
         * read */
        for (master_socket = 0; master_socket <= fdmax; master_socket++)
        {
            if (!FD_ISSET(master_socket, &rdset))
            {
                continue;
            }

            if (master_socket == m_modbusSocket)
            {
                /* A client is asking a new connection */
                socklen_t addrlen;
                struct sockaddr_in clientaddr;
                int newfd;
                /* Handle new connections */
                addrlen = sizeof(clientaddr);
                memset(&clientaddr, 0, sizeof(clientaddr));
                newfd = accept(m_modbusSocket, (struct sockaddr *)&clientaddr, &addrlen);
                if (newfd == -1)
                {
                    perror("Server accept() error");
                }
                else
                {
                    FD_SET(newfd, &refset);

                    if (newfd > fdmax)
                    {
                        /* Keep track of the maximum */
                        fdmax = newfd;
                    }
                    printf("New connection from %s:%d on socket %d\n", inet_ntoa(clientaddr.sin_addr), clientaddr.sin_port, newfd);
                }
            }
            else
            {
                modbus_set_socket(ctx, master_socket);
                rc = modbus_receive(ctx, query);
                if (rc > 0)
                {
                    int offset = modbus_get_header_length(ctx);
                    int slave = query[offset - 1];
                    int function = query[offset];
                    int address = (query[offset + 1] << 8) + query[offset + 2];

                    //std::cout << "slave " << slave << "   func " << function << "   address " << address  << std::endl;
                    slavedev* dev = this->i_slaveMager->findSlave(slave);
                    if (dev)
                    {
                        modbus_mapping_t* mp = dev->getModbusMap();
                        //std::cout << "mp addr server :  " << mp << std::endl;
                        if (0x06 == function || 0x10 == function || 0x05 == function || 0x0f == function)
                        {
                            // 本地模式
                            if (ems_work_mode_local())
                            {
                                // 本地模式直接应答失败
                                modbus_reply_exception(ctx, query, 1);
                                dzlog_info("本地模式");
                                continue;
                            }

                            // 性能计算
                            clock_gettime(CLOCK_MONOTONIC, &g_tbegin);

                            char timeStart[200] = {0};
                            struct timeval time;
                            gettimeofday(&time, NULL);

                            pTempTmStr = localtime(&time.tv_sec);
                            if (NULL != pTempTmStr) {
                                snprintf(timeStart, 199, "%04d-%02d-%02d %02d:%02d:%02d.%03ld",
                                         pTempTmStr->tm_year + 1900,
                                         pTempTmStr->tm_mon + 1,
                                         pTempTmStr->tm_mday,
                                         pTempTmStr->tm_hour,
                                         pTempTmStr->tm_min,
                                         pTempTmStr->tm_sec,
                                         time.tv_usec / 1000);
                            }
                            std::cout << RED << std::endl;
                            dzlog_info("system protect start time:[%s]\n", timeStart);
                            std::cout << RESET << std::endl;

                            // 远程模式
                            int nb = 1;
//                            std::cout << "modbus_reply get func " << std::endl;
                            modbus_reply(ctx, query, rc, dev->getModbusMap());
                            // 写多个保持寄存器
                            if (0x10 == function)
                            {
                                nb = (query[offset + 3] << 8) + query[offset + 4];
                            }
                            else if (0x0f == function)
                            {
                                nb = (query[offset + 3] << 8) + query[offset + 4];
                            }
                            else
                            {
                                nb = 1;
                            }
                            dev->sedMsg2Queue(std::make_shared<msg>(address, function, nb));
                        }
                        else
                        {
                            modbus_reply(ctx, query, rc, dev->getModbusMap());
                        }
                    }
                    else
                    {
                        dzlog_info("dev is null no ack ...");
                    }
                }
                else if (rc == -1)
                {
                    /* This example server in ended on connection closing or
                     * any errors. */
                    dzlog_info("Connection closed on socket %d ", master_socket);
                    close(master_socket);
                    /* Remove from reference set */
                    FD_CLR(master_socket, &refset);
                    if (master_socket == fdmax)
                    {
                        fdmax--;
                    }
                }
            }
        }
    }
    m_initialized = false;
}