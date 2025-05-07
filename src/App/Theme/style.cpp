#include "style.h"

namespace setStyle
{
    void Nord()
    {
        ImGuiStyle& style = ImGui::GetStyle();

        style.WindowRounding = 20.f;
        style.FrameRounding = 6.f;
        // style.FramePadding = ImVec2(2, 2);

        style.Colors[ImGuiCol_WindowBg]      = Colors::winBg;
        style.Colors[ImGuiCol_Button]        = Colors::button;
        style.Colors[ImGuiCol_ButtonHovered] = Colors::buttonHover;

        style.Colors[ImGuiCol_SliderGrab] = Colors::sliderGrab;
        style.GrabRounding = 10.f;

        style.Colors[ImGuiCol_CheckMark]  = Colors::checkMark;
    }
}

