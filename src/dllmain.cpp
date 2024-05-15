#include <Windows.h>
#include "../../src/sdk/jvm.h"
#include "sdk/classes/cls.h"
#include <iostream>
#include "sdk/minecraft/minecraft.h"




void thread_entry(HMODULE module) {
    FILE* output_buffer = nullptr;
    AllocConsole();
    freopen_s(&output_buffer, "CONOUT$", "w", stdout);


    jvm::load();
    cls::load();

    while (!GetAsyncKeyState(VK_DELETE)) {
        //mc::getMinecraft().cached_object;

          std::cout << "mc found: " << mc::getMinecraft().cached_object << ".\n";
        Sleep(200);
    }
    if (output_buffer) {
        fclose(output_buffer);
    }
    FreeConsole();
    FreeLibraryAndExitThread(module, 0ul);
}



void InitConsole() {
    AllocConsole();
    FILE* output_buffer;
    freopen_s(&output_buffer, "CONOUT$", "w", stdout);
    freopen_s(&output_buffer, "CONIN$", "r", stdin);
    printf("Console initialized.\n");
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved, HMODULE hModule) {
    switch (dwReason) {
    case DLL_PROCESS_ATTACH:
    {






        HANDLE thread_handle = CreateThread(nullptr, 0ul, reinterpret_cast<LPTHREAD_START_ROUTINE>(thread_entry), hModule, 0ul, nullptr);

        if (thread_handle && thread_handle != INVALID_HANDLE_VALUE)
        {
            CloseHandle(thread_handle);
        }
        InitConsole();
        DisableThreadLibraryCalls(hMod);

        break;
    }

    case DLL_PROCESS_DETACH:

        break;
    }
    return TRUE;
}
