//
// Created by BREEZE on 2024/7/22.
//

#include "PVZTools.h"

using namespace std;

bool canBeHooked = false;

static DWORD threadProcessID;

static HANDLE process;

// 打开内存
boolean startHook() {
    canBeHooked = false;
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

// 读取肥料地址
DWORD getFertilizerAddress() {
    DWORD basicAddress = 0x006A9EC0;
    DWORD basicAddressValue;

    ReadProcessMemory(process, (LPVOID) basicAddress, &basicAddressValue, sizeof(DWORD), nullptr);

    // offset 1
    DWORD offsetA = basicAddressValue + 0x82C;
    DWORD offsetAValue;
    ReadProcessMemory(process, (LPVOID) offsetA, &offsetAValue, sizeof(DWORD), nullptr);

    // offset 2
    DWORD offsetB = offsetAValue + 0x1F8;
    return offsetB;
}

// 读取智慧树肥料地址
DWORD getTreeFertilizerAddress() {
    DWORD basicAddress = 0x006A9EC0;
    DWORD basicAddressValue;

    ReadProcessMemory(process, (LPVOID) basicAddress, &basicAddressValue, sizeof(DWORD), nullptr);

    // offset 1
    DWORD offsetA = basicAddressValue + 0x82C;
    DWORD offsetAValue;
    ReadProcessMemory(process, (LPVOID) offsetA, &offsetAValue, sizeof(DWORD), nullptr);

    // offset 2
    DWORD offsetB = offsetAValue + 0x230;
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

// 读取除草剂地址
DWORD getHerbicideAddress() {
    DWORD basicAddress = 0x006A9EC0;
    DWORD basicAddressValue;

    ReadProcessMemory(process, (LPVOID) basicAddress, &basicAddressValue, sizeof(DWORD), nullptr);
    // offset 1
    DWORD offsetA = basicAddressValue + 0x82C;
    DWORD offsetAValue;
    ReadProcessMemory(process, (LPVOID) offsetA, &offsetAValue, sizeof(DWORD), nullptr);

    // offset 2
    DWORD offsetB = offsetAValue + 0x1FC;
    return offsetB;
}

// 读取智慧树高度地址
DWORD getTreeHeightAddress() {
    DWORD basicAddress = 0x006A9EC0;
    DWORD basicAddressValue;

    ReadProcessMemory(process, (LPVOID) basicAddress, &basicAddressValue, sizeof(DWORD), nullptr);
    // offset 1
    DWORD offsetA = basicAddressValue + 0x82C;
    DWORD offsetAValue;
    ReadProcessMemory(process, (LPVOID) offsetA, &offsetAValue, sizeof(DWORD), nullptr);

    // offset 2
    DWORD offsetB = offsetAValue + 0x31 * 4 + 0x30;
    return offsetB;
}


// 十个卡槽中一样的值
DWORD getCommonCDAddress() {
    DWORD basicAddress = 0x006A9EC0;
    DWORD basicAddressValue;

    ReadProcessMemory(process, (LPVOID) basicAddress, &basicAddressValue, sizeof(DWORD), nullptr);
    // offset 1
    DWORD offsetA = basicAddressValue + 0x768;
    DWORD offsetAValue;
    ReadProcessMemory(process, (LPVOID) offsetA, &offsetAValue, sizeof(DWORD), nullptr);
    // offset 2
    DWORD offsetB = offsetAValue + 0x144;
    DWORD offsetBValue;
    ReadProcessMemory(process, (LPVOID) offsetB, &offsetBValue, sizeof(DWORD), nullptr);
    return offsetBValue;
}

/**
 * 读取第 i 个卡槽的冷却时间值
 * @param i 0 - 9 对应 1 - 10 的卡槽
 * @return
 */
DWORD getCDIndexAddress(int i) {
    DWORD address = getCommonCDAddress();
    // offset 3
    DWORD offsetC = address + 0x50 * i + 0x70;
    return offsetC;
}

// 获取巧克力地址
DWORD getChocolateAddress() {
    DWORD basicAddress = 0x006A9EC0;
    DWORD basicAddressValue;

    ReadProcessMemory(process, (LPVOID) basicAddress, &basicAddressValue, sizeof(DWORD), nullptr);
    // offset 1
    DWORD offsetA = basicAddressValue + 0x82C;
    DWORD offsetAValue;
    ReadProcessMemory(process, (LPVOID) offsetA, &offsetAValue, sizeof(DWORD), nullptr);
    // offset 2
    DWORD offsetB = offsetAValue + 0x228;
    return offsetB;
}


/**
 * 读取内存地址的值
 * @param address 内存地址
 * @param value 要赋值的地址
 * @return 是否成功
 */
bool readMemoryWithSize(DWORD address, DWORD *value, int size) {
    return ReadProcessMemory(process, (LPVOID) address, &(*value), size, nullptr);
}

/**
 * 写入内存地址
 * @param address 内存地址
 * @param value 要写入的值
 * @return 返回是否成功
 */
bool writeMemoryWithSize(DWORD address, DWORD value, int size) {
    return WriteProcessMemory(process, (LPVOID) address, &value, size, nullptr);
}

/**
 * 读取内存地址的值
 * @param address 内存地址
 * @param value 要赋值的地址
 * @return 是否成功
 */
bool readMemory(DWORD address, DWORD *value) {
    return readMemoryWithSize(address, &(*value), sizeof(DWORD));
}

/**
 * 写入内存地址
 * @param address 内存地址
 * @param value 要写入的值
 * @return 返回是否成功
 */
bool writeMemory(DWORD address, DWORD value) {
    return writeMemoryWithSize(address, value, sizeof(DWORD));
}


/**
 * 设置金币数量
 * @param val 数量
 * @return 是否成功
 */
bool setCoin(int val) {
    if (canBeHooked) {
        return writeMemory(getCoinAddress(), val);
    }
    return false;
}

/**
 * 读取金币数量
 * @return 游戏金币的数量
 */
DWORD getCoin() {
    DWORD val;
    if (canBeHooked) {
        readMemory(getCoinAddress(), &val);
        return val;
    }
    return val;
}

/**
 * 设置游戏阳光数量
 * @param val 阳光数量
 * @return 是否成功
 */
bool setSunshine(int val) {
    if (canBeHooked) {
        return writeMemory(getSunshineAddress(), val);
    }
    return false;
}

/**
 * 读取阳光数量 推荐 9990
 * @return 游戏阳光的数量
 */
DWORD getSunshine() {
    DWORD val;
    if (canBeHooked) {
        readMemory(getSunshineAddress(), &val);
        return val;
    }
    return false;
}

/**
 * 设置游戏肥料数量 推荐10999
 * @param val 肥料数量
 * @return 是否成功
 */
bool setFertilizer(int val) {
    if (canBeHooked) {
        return writeMemory(getFertilizerAddress(), val);
    }
    return false;
}

/**
 * 读取肥料数量
 * @return 游戏阳光的数量
 */
DWORD getFertilizer() {
    DWORD val;
    if (canBeHooked) {
        readMemory(getFertilizerAddress(), &val);
        return val;
    }
    return false;
}

/**
 * 设置游戏除草剂数量 推荐10999
 * @param val 肥料数量
 * @return 是否成功
 */
bool setHerbicide(int val) {
    if (canBeHooked) {
        return writeMemory(getHerbicideAddress(), val);
    }
    return false;
}

/**
 * 读取除草剂数量
 * @return 游戏阳光的数量
 */
DWORD getHerbicide() {
    DWORD val;
    if (canBeHooked) {
        readMemory(getHerbicideAddress(), &val);
        return val;
    }
    return false;
}

/**
 * 设置游戏智慧树肥料数量 推荐10999
 * @param val 肥料数量
 * @return 是否成功
 */
bool setTreeFertilizer(int val) {
    if (canBeHooked) {
        return writeMemory(getTreeFertilizerAddress(), val);
    }
    return false;
}

/**
 * 读取除草剂数量
 * @return 数量
 */
DWORD getTreeFertilizer() {
    DWORD val;
    if (canBeHooked) {
        readMemory(getTreeFertilizerAddress(), &val);
        return val;
    }
    return false;
}

/**
 * 设置游戏智慧树高度
 * @param val 智慧树高度
 * @return 是否成功
 */
bool setTreeHeight(int val) {
    if (canBeHooked) {
        return writeMemory(getTreeHeightAddress(), val);
    }
    return false;
}

/**
 * 读取智慧树高度
 * @return 高度
 */
DWORD getTreeHeight() {
    DWORD val;
    if (canBeHooked) {
        readMemory(getTreeHeightAddress(), &val);
        return val;
    }
    return false;
}

/**
 * 设置游戏卡槽冷却值
 * @param val 是否开启cd
 * @return 是否成功
 */
bool setNoCD(int index, int val) {
    bool isSuccess = false;
    if (canBeHooked) {
        isSuccess = writeMemoryWithSize(getCDIndexAddress(index), val, sizeof(BYTE));
    }
    return isSuccess;
}

/**
 * 读取卡槽CD值
 * @return CD布尔值
 */
DWORD getCD(DWORD address) {
    DWORD val;
    if (canBeHooked) {
        readMemoryWithSize(address, &val, sizeof(BYTE));
        return val;
    }
    return false;
}

/**
 * 设置巧克力的数量 推荐 10999
 * @param count 需要设置的值
 * @return
 */
bool setChocolate(int count) {
    if (canBeHooked) {
        DWORD i = getChocolateAddress();
        return writeMemory(i, count);
    }
    return false;
}

/**
 * 获取巧克力的数量
 * @return
 */
DWORD getChocolateCount() {
    DWORD val;
    if (canBeHooked) {
        DWORD i = getChocolateAddress();
        readMemory(i, &val);
    }
    return val;
}