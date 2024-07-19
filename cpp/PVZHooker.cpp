//
// Created by BREEZE on 2024/7/19.
//

#include "breeze_pvz_cheater_utils_PVZHooker.h"

#include <windows.h>

#include <cstdlib>

using namespace std;


static bool canBeHooked = false;

static DWORD threadProcessID;

static HANDLE process;

// 打开内存
boolean startHook() {
    HWND findWindow = FindWindowW(nullptr, L"植物大战僵尸汉化版");
    if (!findWindow) {
        return canBeHooked;
    }

    if (!GetWindowThreadProcessId(findWindow, &threadProcessID)) {
        return canBeHooked;
    }

    // 打开进程
    process = OpenProcess(PROCESS_ALL_ACCESS, false, threadProcessID);
    if (process == nullptr) {
        return canBeHooked;
    }
    canBeHooked = true;
    return canBeHooked;
}

// 读取阳光地址
DWORD getSunshineAddress() {
    DWORD basicAddress = 0x006A9EC0;
    DWORD basicAddressValue;

    ReadProcessMemory(process, (LPVOID) basicAddress, &basicAddressValue, sizeof(DWORD), nullptr);

    // offset 1
    DWORD offsetA = basicAddressValue + 0x768;
    DWORD offsetAValue;
    ReadProcessMemory(process, (LPVOID) offsetA, &offsetAValue, sizeof(DWORD), nullptr);

    // offset 2
    DWORD offsetB = offsetAValue + 0x5560;
    return offsetB;
}

// 读取金币地址
DWORD getCoinAddress() {
    DWORD basicAddress = 0x006A9EC0;
    DWORD basicAddressValue;

    ReadProcessMemory(process, (LPVOID) basicAddress, &basicAddressValue, sizeof(DWORD), nullptr);
    // offset 1
    DWORD offsetA = basicAddressValue + 0x0000082C;
    DWORD offsetAValue;
    ReadProcessMemory(process, (LPVOID) offsetA, &offsetAValue, sizeof(DWORD), nullptr);

    // offset 2
    DWORD offsetB = offsetAValue + 0x28;
    return offsetB;
}

bool readMemory(DWORD address, DWORD *value) {
    return ReadProcessMemory(process, (LPVOID) address, &(*value), sizeof(DWORD), nullptr);
}

bool writeMemory(DWORD address, DWORD value) {
    return WriteProcessMemory(process, (LPVOID) address, &value, sizeof(DWORD), nullptr);
}

JNIEXPORT jboolean JNICALL Java_breeze_pvz_cheater_utils_PVZHooker_isRunning
        (JNIEnv *env, jclass clazz) {
    return startHook();
}

JNIEXPORT void JNICALL Java_breeze_pvz_cheater_utils_PVZHooker_infinitSunshine
        (JNIEnv *env, jclass clazz, jboolean lock) {
    writeMemory(getSunshineAddress(), 9990);
}

JNIEXPORT void JNICALL Java_breeze_pvz_cheater_utils_PVZHooker_infinitCoin
        (JNIEnv *env, jclass clazz, jboolean lock) {
    writeMemory(getCoinAddress(), 9999999);
}
