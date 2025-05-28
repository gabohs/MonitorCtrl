#pragma once

#include "../MonitorControl/MonitorCtrl.h"
#include "../MonitorControl/MonitorSpecs.h"

#include <imgui.h>
#include "../../Theme/colors.h"


class GUI
{
private:
    ImVec2 panelSize = {250, 250};
    ImVec2 lastWindowPos_;
    ImVec2 lastWindowSize_;
    bool shouldRender_ = true;

private:
    MonitorCtrl monitorCtrl;
    MonitorSpecs specs_;
   
    void renderCustomTitleBar();

    void ControlsTab();
    void brightnessSlider();
    void contrastSlider();
    void tempSlider();

    void AdvancedTab();
    void restoringOptions();
    void powerOptions();
 
public:
    GUI();
    bool shouldRender();

    ImVec2 getWindowPos();
    ImVec2 getWindowSize();
    ImVec2 getMousePos();

    void render();
};