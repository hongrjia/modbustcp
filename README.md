## 1.简介
线圈（Coils）：

线圈用于表示输出寄存器，通常对应可控制的开关设备，如继电器、灯等。
线圈可以被写入，以改变相关设备的状态。
Modbus功能码为05（写单个线圈）和15（写多个线圈）。

输入线圈（Discrete Inputs）：

输入线圈用于表示输入寄存器，通常对应不可控制的开关设备，如传感器状态、按钮状态等。
输入线圈通常只能读取，不能被写入。
Modbus功能码为02（读取离散输入）。

保持寄存器（Holding Registers）：

保持寄存器是Modbus设备上存储数据的可读可写的寄存器。这些寄存器通常用于存储设备的配置参数、控制信息和其他操作所需的数据。
在Modbus协议中，保持寄存器 读写

输入寄存器（Input Registers）：

输入寄存器是Modbus设备上存储只读数据的寄存器。这些寄存器通常用于存储设备的状态信息、测量值和其他只读的数据。
在Modbus协议中，输入寄存器 只读

## 2.服务说明
### 2.1 服务进程路径：
/app/aarch64/lems/service/modbusTcp
```bash
.
├── config -> /app/aarch64/lems/config/modbusTcp_conf
├── modbus.conf
├── modbusTcpSrv
└── modbusvr.lock
```

### 2.2 支持情况
|  | 支持情况  |  备注  |
| ------ | ----  | :------:  |
| 多个 slave | 支持 |  |
| 寄存器信息配置 | 支持 |  |
| 不同类型寄存器读写 | 支持 |  |

**已知问题** 
- 心跳功能目前没有增加。
- 内存部分存在优化空间。

## 3. 联系人信息

维护人：[huanglingjie][1]

[1]: http://192.168.11.62/huanglingjie/modbustcp_svr_base_line