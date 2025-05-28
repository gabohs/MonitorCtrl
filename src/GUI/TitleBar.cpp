#include "GUI.h"

void GUI::renderCustomTitleBar()
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