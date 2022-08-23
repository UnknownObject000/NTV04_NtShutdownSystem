# NTV04_NtShutdownSystem
NTAPI快速关闭计算机视频源代码，用于演示未公开的API - NtShutdownSystem

## 关于NtShutdownSystem

### 函数原型
```c++
DWORD NtShutdownSystem(SHUTDOWN_ACTION Action);
```

### 函数指针类型
```c++
typedef DWORD(WINAPI* typeNtShutdownSystem)(SHUTDOWN_ACTION Action);
```

### 未导出类型
 - SHUTDOWN_ACTION
```c++
typedef enum _SHUTDOWN_ACTION
{
    ShutdownNoReboot,
    ShutdownReboot,
    ShutdownPowerOff
} SHUTDOWN_ACTION;
```

### 所在DLL
 - ntdll.dll
