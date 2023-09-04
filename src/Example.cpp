#include "main.h"

void startup_thread(HMODULE hModule)
{
    log::init();
    log::Message("Example is loaded.");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{

    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        // 创建线程
        ::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)startup_thread, NULL, NULL, NULL);
    }

    return TRUE;
}
