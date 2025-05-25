#pragma once

#include <windows.h>

struct MonitorSpecs
{
    DWORD minBrightness;
    DWORD maxBrightness;
    DWORD curBrightness;

    DWORD minContrast;
    DWORD maxContrast;
    DWORD curContrast;
};