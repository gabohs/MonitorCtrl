#pragma once

#include <windows.h>
#include "MonitorSpecs.h"

namespace util
{   
    inline bool isMonitorValueError(DWORD value) { return value == MONITOR_VALUE_ERROR; }

    const char* colorTempToStr(int value);
    const char* techTypeToStr(int value);

    void displayInfoAsTable(DWORD info, const char* label, DWORD flag);
    void displayBitmaskInfoAsTable(DWORD info, const char* label, DWORD flag);
}