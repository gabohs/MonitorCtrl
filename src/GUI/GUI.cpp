#include "GUI.h"

GUI::GUI()
{
    specs_ = monitorCtrl.getSpecs();
}

bool GUI::shouldRender()
{
    return shouldRender_;
}

ImVec2 GUI::getWindowPos()
{   
    return lastWindowPos_;
}

ImVec2 GUI::getWindowSize()
{
    return lastWindowSize_;
}

ImVec2 GUI::getMousePos()
{
    return ImGui::GetMousePos();
}

void GUI::render()
{
    ImGui::SetNextWindowSize(panelSize, ImGuiCond_Once);
    ImGui::Begin("MonitorCtrl", nullptr, ImGuiWindowFlags_NoTitleBar);

    lastWindowPos_ = ImGui::GetWindowPos();
    lastWindowSize_ = ImGui::GetWindowSize();

    renderCustomTitleBar();

    if (ImGui::BeginTabBar("Tabs"))
    {   
        if (ImGui::BeginTabItem("Controls"))
        {
            ControlsTab();
            ImGui::Text("Number of monitors: %d", monitorCtrl.getMonitorCount());   
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Advanced"))
        {
            AdvancedTab();
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();  
    } 
    ImGui::End();
}