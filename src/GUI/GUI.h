#pragma once

#include "../MonitorControl/MonitorCtrl.h"
#include "../MonitorControl/MonitorSpecs.h"


class GUI
{
private:
    MonitorCtrl monitorCtrl;
    MonitorSpecs specs_;

    bool shouldRender_ = true;

    void renderCustomCloseButton();

    void ControlsTab();
    void brightnessSlider();
    void contrastSlider();

    void AdvancedTab();
    void restoringOptions();
    void powerOptions();

    
public:
    GUI();
    bool shouldRender();

    void render();

};