#include "GUI.h"

#include <imgui.h>

#include "../../Theme/colors.h"

GUI::GUI()
{
    specs_ = monitorCtrl.getSpecs();
}

void GUI::renderCustomCloseButton()
{
    ImGui::BeginGroup();

    ImGui::Text("MonitorCtrl");

    ImGui::SameLine(ImGui::GetWindowWidth() - 35); // Close button

    float radius = 7.0f;
    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImVec2 center = ImVec2(pos.x + radius, pos.y + radius);

    ImGui::InvisibleButton("##close_button", ImVec2(radius * 2, radius * 2));

    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    draw_list->AddCircleFilled(center, radius, ImGui::ColorConvertFloat4ToU32(Colors::Red));

    // close window if clicked
    if (ImGui::IsItemClicked()) 
    {
        shouldRender_ = false;
    }

    ImGui::EndGroup();
}

void GUI::ControlsTab()
{
    brightnessSlider();
    contrastSlider();
}

void GUI::brightnessSlider()
{   
    static int brightnessVal = specs_.curBrightness; 

    ImGui::Text("Brightness");

    ImGui::SameLine();
    ImGui::TextColored(Colors::LightBlue, "%d", brightnessVal);
     
    ImGui::SliderInt("##BrightnessSlider", &brightnessVal, specs_.minBrightness, specs_.maxBrightness, "");

    ImGui::SameLine();
    if (ImGui::ArrowButton("##ArrowLeftBrightness", ImGuiDir_Left))
    {
        brightnessVal--;
    }
    ImGui::SameLine();
    if (ImGui::ArrowButton("##ArrowRightBrightness", ImGuiDir_Right))
    {
        brightnessVal++;
    }

    static int lastSetVal = brightnessVal; // to avoid calling setBrightness() every frame, which causes lag

    if (brightnessVal != lastSetVal)
    {   
        monitorCtrl.setBrightness(brightnessVal);
        lastSetVal = brightnessVal;
    }
}

void GUI::contrastSlider()
{   
    static int contrastVal = specs_.curContrast; 

    ImGui::Text("Contrast");

    ImGui::SameLine();
    ImGui::TextColored(Colors::LightBlue, "%d", contrastVal);

    ImGui::SliderInt("##ContrastSlider", &contrastVal, specs_.minContrast, specs_.maxContrast, "");

    ImGui::SameLine();
    if (ImGui::ArrowButton("##ArrowLeftContrast", ImGuiDir_Left))
    {
        contrastVal--;
    }
    ImGui::SameLine();
    if (ImGui::ArrowButton("##ArrowRightContrast", ImGuiDir_Right))
    {
        contrastVal++;
    }

    static int lastSetVal = contrastVal; // to avoid calling setContrast() every frame, which causes lag

    if (contrastVal != lastSetVal)
    {   
        monitorCtrl.setContrast(contrastVal);
        lastSetVal = contrastVal;
    }
}

void GUI::AdvancedTab()
{   
    restoringOptions();
    powerOptions();
}

void GUI::restoringOptions()
{   
    ImGui::Text("Restoring Options:");

    ImGui::Separator();
    ImGui::Dummy(ImVec2(0.0f, 3.0f));

    ImGui::PushStyleColor(ImGuiCol_Button, Colors::Red);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, Colors::BrightRed);
    ImGui::PushStyleColor(ImGuiCol_Text, Colors::DarkGray);

    if (ImGui::SmallButton("Restore to Factory Defaults"))
    {
        monitorCtrl.restoreFactoryDefaults();
    }

    ImGui::Dummy(ImVec2(0.0f, 5.0f));

    if (ImGui::SmallButton("Restore colors"))
    {
        monitorCtrl.restoreColorDefaults();
    }

    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
    
}

void GUI::powerOptions()
{   
    ImGui::Dummy(ImVec2(0.0f, 3.0f));
    ImGui::Text("Power Options:");

    ImGui::Separator();
    ImGui::Dummy(ImVec2(0.0f, 3.0f));

    if (ImGui::SmallButton("Turn ON"))
    {
        monitorCtrl.turnOn();
    }

    ImGui::PushStyleColor(ImGuiCol_Button, Colors::Red);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, Colors::BrightRed);
    ImGui::PushStyleColor(ImGuiCol_Text, Colors::DarkGray);

    ImGui::SameLine();
    if (ImGui::SmallButton("Turn OFF"))
    {   
        Sleep(1000);
        monitorCtrl.turnOff();
    }

    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
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
    ImGui::SetNextWindowSize(ImVec2(250, 200), ImGuiCond_Once);
    ImGui::Begin("MonitorCtrl", nullptr, ImGuiWindowFlags_NoTitleBar);

    lastWindowPos_ = ImGui::GetWindowPos();
    lastWindowSize_ = ImGui::GetWindowSize();

    renderCustomCloseButton();

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