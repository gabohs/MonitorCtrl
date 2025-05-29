#pragma once

#include "../MonitorControl/MonitorCtrl.h"
#include "../MonitorControl/MonitorSpecs.h"

#include <imgui.h>
#include "../../Theme/colors.h"

#include "../MonitorControl/Util.h"

class GUI
{
private:
    ImVec2 panelSize = {400, 400};
    ImVec2 lastWindowPos_;
    ImVec2 lastWindowSize_;
    bool shouldRender_ = true;
    bool shouldMinimize_ = false;

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

    void InfoTab();
    void monitorCapabilitiesTable();
    void supColorTempsTable();
 
public:
    GUI();
    bool shouldRender();
    bool shouldMinimize();
    void setShouldMinize(bool value);

    ImVec2 getWindowPos();
    ImVec2 getWindowSize();
    ImVec2 getMousePos();

    void render();
};