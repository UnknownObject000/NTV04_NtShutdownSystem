#pragma once
#include <Windows.h>

//׼��δ����ö������
typedef enum _SHUTDOWN_ACTION
{
    ShutdownNoReboot,
    ShutdownReboot,
    ShutdownPowerOff
} SHUTDOWN_ACTION;

//׼������ָ������
typedef DWORD(WINAPI* typeNtShutdownSystem)(SHUTDOWN_ACTION Action);

//�������ڻ�ȡ�ػ���Ȩ�ĺ���
bool GetShutdownPrivilege();

//����δ������API
DWORD NtShutdownSystem(SHUTDOWN_ACTION action);