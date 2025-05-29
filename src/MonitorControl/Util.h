#pragma once

#include <windows.h>

namespace util
{
    const char* colorTempToStr(int value);

    void displayInfoAsTable(DWORD info, const char* label, DWORD flag);
}