#include "MonitorCtrl.h"

MonitorCtrl::MonitorCtrl()
{
    hMonitor_ = MonitorFromWindow(GetDesktopWindow(), MONITOR_DEFAULTTOPRIMARY);
    GetNumberOfPhysicalMonitorsFromHMONITOR(hMonitor_, &monitorCount_);
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
    }
}

void MonitorCtrl::setBrightness(DWORD value)
{ 
    BOOL result = SetMonitorBrightness(pMons_[0].hPhysicalMonitor, value);
    if (!result) 
    {
        MessageBox(NULL, TEXT("Failed to set contrast."), TEXT("Error"), MB_OK | MB_ICONERROR);
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

void MonitorCtrl::restoreFactoryDefaults()
{
    RestoreMonitorFactoryDefaults(pMons_[0].hPhysicalMonitor);
}

void MonitorCtrl::restoreColorDefauls()
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
