#include "GUI.h"

void GUI::renderCustomTitleBar()
{
    ImGui::BeginGroup();

    ImGui::Text("MonitorCtrl");

    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    float radius = 7.0f;
    float spacing = 10.0f; // space between buttons

    // Minimize button (YELLOW)
    ImGui::SameLine(ImGui::GetWindowWidth() - (radius * 4 + spacing) - 22); // Close button

    ImVec2 yellowPos = ImGui::GetCursorScreenPos();
    ImVec2 yellowCenter = ImVec2(yellowPos.x + radius, yellowPos.y + radius);

    ImGui::InvisibleButton("##minimize_button", ImVec2(radius * 2, radius * 2));
    draw_list->AddCircleFilled(yellowCenter, radius, ImGui::ColorConvertFloat4ToU32(Colors::Yellow));

    if (ImGui::IsItemClicked())
    {
        shouldMinimize_ = true;
    }

    ImGui::SameLine(0.0f, spacing);
    

    // Close button (RED)
    ImVec2 redPos = ImGui::GetCursorScreenPos();
    ImVec2 redCenter = ImVec2(redPos.x + radius, redPos.y + radius);

    ImGui::InvisibleButton("##close_button", ImVec2(radius * 2, radius * 2));
    
    draw_list->AddCircleFilled(redCenter, radius, ImGui::ColorConvertFloat4ToU32(Colors::Red));

    if (ImGui::IsItemClicked())
    {
        shouldRender_ = false;
    }

    ImGui::EndGroup();
}