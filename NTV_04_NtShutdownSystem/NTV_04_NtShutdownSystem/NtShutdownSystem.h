#pragma once
#include <Windows.h>

//准备未导出枚举类型
typedef enum _SHUTDOWN_ACTION
{
    ShutdownNoReboot,
    ShutdownReboot,
    ShutdownPowerOff
} SHUTDOWN_ACTION;

//准备函数指针类型
typedef DWORD(WINAPI* typeNtShutdownSystem)(SHUTDOWN_ACTION Action);

//声明用于获取关机特权的函数
bool GetShutdownPrivilege();

//声明未导出的API
DWORD NtShutdownSystem(SHUTDOWN_ACTION action);