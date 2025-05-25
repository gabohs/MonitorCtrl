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

    void setBrightness(DWORD value);
    void setContrast(DWORD value);

    void restoreFactoryDefaults();
    void restoreColorDefauls();

    void turnOn();
    void turnOff();

    MonitorSpecs& getSpecs();
};