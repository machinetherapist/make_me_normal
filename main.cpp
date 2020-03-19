#include "pch.h"
#include <iostream>
 
const uintptr_t LAGbase = (uintptr_t)GetModuleHandleA("Make me LAG.exe");
 
void createConsole(const char* title) {
    AllocConsole();
    SetConsoleTitleA(title);
 
    freopen_s((FILE**)stdout, "conout$", "w", stdout);
    std::cout << "Make me NORMAL v1 and probly last by machinetherapist" << std::endl;
    std::cout << "RUN: F1 ( 59 - 45 ) " << std::endl;
    std::cout << "JUMP: F2 (44 - 25 )" << std::endl;
    std::cout << "ATTACK: F3 ( 24 - 1 ) " << std::endl;
    std::cout << "SHOW CURRENT FPS: F4" << std::endl;
    std::cout << "0 FPS: F5" << std::endl;
 
}
 
auto playCasual() -> void {
 
    // create console 
    createConsole("Make me NORMAL");
 
 
    int* FPS = (int*)(LAGbase + 0x64E62C);	//creates a pointer to fps
 
 
    while (true) {
        if (GetAsyncKeyState(VK_F4)) {
            std::cout << "Current: "<< *FPS << std::endl;
            Sleep(250);
        }
        if (GetAsyncKeyState(VK_F1)) {
            *FPS = 50;
        }
        if (GetAsyncKeyState(VK_F2)) {
            *FPS = 30;
        }
        if (GetAsyncKeyState(VK_F3)) {
            *FPS = 10;
        }
        if (GetAsyncKeyState(VK_F5)) {
            *FPS = 0;
            Sleep(250);
        }
    }
 
}
 
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)playCasual, 0, 0, 0);
 
    return TRUE;
}
