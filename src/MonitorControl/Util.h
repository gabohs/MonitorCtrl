#pragma once

#include <windows.h>

namespace util
{
    const char* colorTempToStr(int value);
    const char* techTypeToStr(int value);

    void displayInfoAsTable(DWORD info, const char* label, DWORD flag);
    void displayBitmaskInfoAsTable(DWORD info, const char* label, DWORD flag);
}