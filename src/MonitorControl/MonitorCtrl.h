#pragma once

#include <windows.h>
#include <physicalmonitorenumerationapi.h>
#include <highlevelmonitorconfigurationapi.h>
#include <PhysicalMonitorEnumerationAPI.h>

#include <iostream>

#include "MonitorSpecs.h"

#pragma comment(lib, "Dxva2.lib")

class MonitorCtrl
{
private:
    MonitorSpecs specs_;

    HMONITOR hMonitor_;
    DWORD monitorCount_;
    PHYSICAL_MONITOR* pMons_;

public:
    MonitorCtrl();
    ~MonitorCtrl();

    void getMonitorInfo();
    DWORD getMonitorCount();

    void setBrightness(DWORD value);
    void setContrast(DWORD value);
    void setColorTemperature(int value);

    void restoreFactoryDefaults();
    void restoreColorDefaults();

    void turnOn();
    void turnOff();

    MonitorSpecs& getSpecs();
};