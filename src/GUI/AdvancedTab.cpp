#include "GUI.h"

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

void GUI::AdvancedTab()
{   
    restoringOptions();
    powerOptions();
}