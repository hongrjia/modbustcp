//
// Created by Administrator on 2023/11/20.
//

#ifndef MODBUS_SERVER_MISC_H
#define MODBUS_SERVER_MISC_H

#endif //MODBUS_SERVER_MISC_H

#include"zlog.h"

int ems_work_mode_local(void);
int IsProcessRunning();
int mic_task_init(void);
void gitVer(void);
int mic_modbus_task(void);

/***
 * @func    初始化日志系统
 * @return  -1错误 0成功
 */
int InitLog();