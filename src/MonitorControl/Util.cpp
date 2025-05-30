#include "Util.h"

#include <highlevelmonitorconfigurationapi.h>
#include <imgui.h>
#include "../../Theme/colors.h"

namespace util
{
    const char* colorTempToStr(int value)
    {
        switch ((_MC_COLOR_TEMPERATURE)value)
        {
            case MC_COLOR_TEMPERATURE_4000K:
            {
                return "4000K";
            } break;

            case MC_COLOR_TEMPERATURE_5000K:
            {
                return "5000K";
            } break;

            case MC_COLOR_TEMPERATURE_6500K:
            {
                return "6500K";
            } break;

            case MC_COLOR_TEMPERATURE_7500K:
            {
                return "7500K";
            } break;

            case MC_COLOR_TEMPERATURE_8200K:
            {
                return "8200K";
            } break;

            case MC_COLOR_TEMPERATURE_9300K:
            {
                return "9300K";
            } break;

            case MC_COLOR_TEMPERATURE_10000K:
            {
                return "10000K";
            } break;

            case MC_COLOR_TEMPERATURE_11500K:
            {
                return "11500K";
            } break;

            default:
            {
                return "Unknown";
            }
        }
    }

    const char* techTypeToStr(int value)
    {
        switch ((MC_DISPLAY_TECHNOLOGY_TYPE)value)
        {
            case MC_SHADOW_MASK_CATHODE_RAY_TUBE:
            {
                return "Shadow Mask CRT";
            } break;

            case MC_APERTURE_GRILL_CATHODE_RAY_TUBE:
            {
                return "Aperture Grill CRT";
            } break;

            case MC_THIN_FILM_TRANSISTOR:
            {
                return "TFT (Thin-Film Transistor)";
            } break;

            case MC_LIQUID_CRYSTAL_ON_SILICON:
            {
                return "LCoS (Liquid Crystal on Silicon)";
            } break;

            case MC_PLASMA:
            {
                return "Plasma";
            } break;

            case MC_ORGANIC_LIGHT_EMITTING_DIODE:
            {
                return "OLED";
            } break;

            case MC_ELECTROLUMINESCENT:
            {
                return "Electroluminescent";
            } break;

            case MC_MICROELECTROMECHANICAL:
            {
                return "MEMS (Microelectromechanical)";
            } break;

            case MC_FIELD_EMISSION_DEVICE:
            {
                return "Field Emission Display";
            } break;

            default:
            {
                return "Unknown";
            }
        }
    }

    void displayInfoAsTable(DWORD info, const char *label, DWORD flag)
    {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("%s", label);
        ImGui::TableSetColumnIndex(1);

        if (info == flag)
            ImGui::TextColored(Colors::Green, "YES");
        else
            ImGui::TextColored(Colors::BrightRed, "NO");
    }

    void displayBitmaskInfoAsTable(DWORD info, const char *label, DWORD flag)
    {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("%s", label);
        ImGui::TableSetColumnIndex(1);

        if (info & flag)
            ImGui::TextColored(Colors::Green, "YES");
        else
            ImGui::TextColored(Colors::BrightRed, "NO");
    }
}
