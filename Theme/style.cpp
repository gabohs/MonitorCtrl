#include "style.h"

namespace setStyle
{
    void GruvBox_Dark()
    {
        ImGuiStyle& style = ImGui::GetStyle();

        style.WindowRounding = 10.f;
        style.FrameRounding  = 4.f;
        style.GrabRounding   = 10.f;
        style.PopupRounding  = 4.f;
        style.ScrollbarSize  = 10.f;
        
        style.Colors[ImGuiCol_WindowBg]             = Colors::winBg;
        style.Colors[ImGuiCol_TitleBg]              = Colors::TitleBar;
        style.Colors[ImGuiCol_TitleBgActive]        = Colors::TitleBarActive;
        style.Colors[ImGuiCol_ResizeGrip]           = Colors::Orange;

        style.Colors[ImGuiCol_Text]                 = Colors::Orange;

        style.Colors[ImGuiCol_Button]               = Colors::LightBlue;
        style.Colors[ImGuiCol_ButtonHovered]        = Colors::DarkBlue;

        style.Colors[ImGuiCol_FrameBg]              = Colors::Gray;
        style.Colors[ImGuiCol_InputTextCursor]      = Colors::Orange;

        style.Colors[ImGuiCol_PopupBg]              = Colors::DarkGray;

        style.Colors[ImGuiCol_ScrollbarBg]          = Colors::Transparent;
        style.Colors[ImGuiCol_ScrollbarGrab]        = Colors::Gray;
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = Colors::Orange;
        style.Colors[ImGuiCol_ScrollbarGrabActive]  = Colors::LightOrange;

        style.Colors[ImGuiCol_SliderGrab]           = Colors::Orange;
        style.Colors[ImGuiCol_SliderGrabActive]     = Colors::BrightRed;

        style.Colors[ImGuiCol_Tab]                  = Colors::DarkBlue;
        style.Colors[ImGuiCol_TabActive]            = Colors::LightBlue;
    }
}

