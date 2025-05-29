#include "MonitorCtrl.h"

MonitorCtrl::MonitorCtrl()
{
    hMonitor_ = MonitorFromWindow(GetDesktopWindow(), MONITOR_DEFAULTTOPRIMARY);
    BOOL monitorFound = GetNumberOfPhysicalMonitorsFromHMONITOR(hMonitor_, &monitorCount_);
    if (!monitorFound)
    {
        MessageBox(NULL, TEXT("No physical monitors found."), TEXT("Error"), MB_OK | MB_ICONERROR);
        return;
    }

    pMons_ = new PHYSICAL_MONITOR[monitorCount_];

    getMonitorInfo();
}

MonitorCtrl::~MonitorCtrl()
{   
    DestroyPhysicalMonitors(monitorCount_, pMons_); 
    delete[] pMons_;
}

void MonitorCtrl::getMonitorInfo()
{
    if (GetPhysicalMonitorsFromHMONITOR(hMonitor_, monitorCount_, pMons_)) 
    {
        GetMonitorBrightness(pMons_[0].hPhysicalMonitor, &specs_.minBrightness, &specs_.curBrightness, &specs_.maxBrightness);
        GetMonitorContrast(pMons_[0].hPhysicalMonitor, &specs_.minContrast, &specs_.curContrast, &specs_.maxContrast);  
        GetMonitorColorTemperature(pMons_[0].hPhysicalMonitor, (LPMC_COLOR_TEMPERATURE)&specs_.curTemp); 

        getMonitorCapabilities();
    }
    else
    {
        MessageBox(NULL, TEXT("Failed to get Physical Monitor."), TEXT("Error"), MB_OK | MB_ICONERROR);
    } 
}

DWORD MonitorCtrl::getMonitorCount()
{
    return monitorCount_;
}

void MonitorCtrl::getMonitorCapabilities()
{
    BOOL result = GetMonitorCapabilities(pMons_[0].hPhysicalMonitor, &specs_.capabilities, &specs_.supportedColorTemps);
    if (!result) 
    {
        DWORD error = GetLastError();
        printf("GetMonitorCapabilities failed: %lu\n", error);
    }
}

void MonitorCtrl::setBrightness(DWORD value)
{ 
    BOOL result = SetMonitorBrightness(pMons_[0].hPhysicalMonitor, value);
    if (!result) 
    {
        MessageBox(NULL, TEXT("Failed to set brightness."), TEXT("Error"), MB_OK | MB_ICONERROR);
    }
    else
    {
        specs_.curContrast = value;
        
    }
}

void MonitorCtrl::setContrast(DWORD value)
{
    BOOL result = SetMonitorContrast(pMons_[0].hPhysicalMonitor, value);
    if (!result) 
    {
        MessageBox(NULL, TEXT("Failed to set contrast."), TEXT("Error"), MB_OK | MB_ICONERROR);
    }
    else
    {
        specs_.curContrast = value;
    } 
}

void MonitorCtrl::setColorTemperature(int value)
{
    BOOL result = SetMonitorColorTemperature(pMons_[0].hPhysicalMonitor, (_MC_COLOR_TEMPERATURE)value);
    if (!result)
    {
        MessageBox(NULL, TEXT("Failed to set color temperature."), TEXT("Error"), MB_OK | MB_ICONERROR);
    }
    else
    {
        specs_.curTemp = value; 
        // value is stored on the MonitorSpecs struct as an integer, from 1 to 8, corresponding to the equivalent index 
        // of the _MC_COLOR_TEMPERATURE enum element 
    }
}

void MonitorCtrl::restoreFactoryDefaults()
{
    RestoreMonitorFactoryDefaults(pMons_[0].hPhysicalMonitor);
}

void MonitorCtrl::restoreColorDefaults()
{
    RestoreMonitorFactoryColorDefaults(pMons_[0].hPhysicalMonitor);
}

void MonitorCtrl::turnOn()
{
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)-1);
}

void MonitorCtrl::turnOff()
{
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
}

MonitorSpecs &MonitorCtrl::getSpecs()
{
    return specs_;
}
