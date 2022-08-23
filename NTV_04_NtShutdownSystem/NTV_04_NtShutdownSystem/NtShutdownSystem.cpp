#include "pch.h"
#include "NtShutdownSystem.h"

bool GetShutdownPrivilege()
{
	HANDLE hToken;
	TOKEN_PRIVILEGES TokenPriv;
	LUID ShutdownPrivilegeID;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
		return false;
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &ShutdownPrivilegeID);
	TokenPriv.PrivilegeCount = 1;
	TokenPriv.Privileges[0].Luid = ShutdownPrivilegeID;
	TokenPriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	return AdjustTokenPrivileges(hToken, FALSE, &TokenPriv, NULL, NULL, NULL);
}

DWORD NtShutdownSystem(SHUTDOWN_ACTION action)
{
	HMODULE hDll = GetModuleHandle(L"ntdll.dll");
	if (hDll == nullptr)
		return -1;
	typeNtShutdownSystem func = (typeNtShutdownSystem)GetProcAddress(hDll, "NtShutdownSystem");
	return func(action);
}
