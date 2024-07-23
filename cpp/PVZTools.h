//
// Created by BREEZE on 2024/7/22.
//

#include <windows.h>

#include <cstdlib>

#ifndef PVZHOOKER_PVZTOOLS_H
#define PVZHOOKER_PVZTOOLS_H

extern bool canBeHooked;

boolean startHook();

bool readMemory(DWORD, DWORD *);

bool writeMemory(DWORD, DWORD);

bool setCoin(int val);

DWORD getCoin();

bool setSunshine(int val);

DWORD getSunshine();

bool setFertilizer(int val);

DWORD getFertilizer();


bool setHerbicide(int val);

DWORD getHerbicide();

bool setTreeFertilizer(int val);

DWORD getTreeFertilizer();

bool setTreeHeight(int val);

DWORD getTreeHeight();

#endif //PVZHOOKER_PVZTOOLS_H
