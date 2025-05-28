#include "GUI.h"

#include "../MonitorControl/Util.h"

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

void GUI::tempSlider()
{
    static int tempVal = specs_.curTemp;

    ImGui::Text("Color Temperature");

    ImGui::SameLine();
    ImGui::TextColored(Colors::LightBlue, "%s", util::colorTempToStr(tempVal));

    ImGui::SliderInt("##TempSlider", &tempVal, 1, 8, "");

    ImGui::SameLine(); 
    if (ImGui::ArrowButton("##ArrowLeftTemp", ImGuiDir_Left))
    {
        tempVal--;
    }

    ImGui::SameLine();
    if (ImGui::ArrowButton("##ArrowRightTemp", ImGuiDir_Right))
    {
        tempVal++;
    }

    static int lastSetVal = tempVal;

    if (tempVal != lastSetVal)
    {
        monitorCtrl.setColorTemperature(tempVal);
        lastSetVal = tempVal;
    }
}

void GUI::ControlsTab()
{
    brightnessSlider();
    contrastSlider();
    tempSlider();
}