#pragma once

#include <windows.h>

#define MONITOR_VALUE_ERROR 0xFFFFFFFF

struct MonitorSpecs
{   
    DWORD capabilities;
    DWORD supportedColorTemps;

    DWORD tech;

    DWORD minBrightness = 0;
    DWORD maxBrightness = 100;
    DWORD curBrightness = 0;

    DWORD minContrast = 0;
    DWORD maxContrast = 100;
    DWORD curContrast = 0;

    int curTemp;
};