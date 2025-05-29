#include "GUI.h"

#include <map>

void GUI::monitorCapabilitiesTable()
{
    ImGui::TextColored(Colors::Aqua, "Monitor Capabilities:");

    if (ImGui::BeginItemTooltip())
    {
        ImGui::TextColored(Colors::Red, "*Sometimes info can be innacurate");
        ImGui::EndTooltip();
    }

    if (ImGui::BeginTable("CapabilitiesTable", 2, ImGuiTableFlags_Borders))
    {
        ImGui::TableSetupColumn("Feature");
        ImGui::TableSetupColumn("Supported");

        std::map<const char*, uint32_t> capabilitiesMap = 
        {
            { "Brightness",                     MC_CAPS_BRIGHTNESS                     },
            { "Contrast",                       MC_CAPS_CONTRAST                       },
            { "Color Temperature",              MC_CAPS_COLOR_TEMPERATURE              },
            { "RGB Gain",                       MC_CAPS_RED_GREEN_BLUE_GAIN            },
            { "RGB Drive",                      MC_CAPS_RED_GREEN_BLUE_DRIVE           },
            { "Degauss",                        MC_CAPS_DEGAUSS                        },
            { "Display Area Position",          MC_CAPS_DISPLAY_AREA_POSITION          },
            { "Display Area Size",              MC_CAPS_DISPLAY_AREA_SIZE              },
            { "Restore Factory Defaults",       MC_CAPS_RESTORE_FACTORY_DEFAULTS       },
            { "Restore Factory Color Defaults", MC_CAPS_RESTORE_FACTORY_COLOR_DEFAULTS }
        };

        for (auto& [label, flag] : capabilitiesMap)
        {
            util::displayInfoAsTable(specs_.capabilities, label, flag);
        }

        ImGui::EndTable();
    }
}

void GUI::supColorTempsTable()
{
    ImGui::TextColored(Colors::Yellow, "Supported Color Temperatures:");

    if (ImGui::BeginItemTooltip())
    {
        ImGui::TextColored(Colors::Red, "*Sometimes info can be innacurate");
        ImGui::EndTooltip();
    }

    if (ImGui::BeginTable("CapabilitiesTable", 2, ImGuiTableFlags_Borders))
    {
        ImGui::TableSetupColumn("Temperature:");
        ImGui::TableSetupColumn("Supported");

        for (int i = 1; i < 9; i++) 
        {   
            // the 1st element of the _MC_COLOR_TEMPERATURE enum is "Unknown"; thus we start the loop at 1 and end at index 8, 
            // the last valid color in the enum
            util::displayInfoAsTable(specs_.supportedColorTemps, util::colorTempToStr(i), (_MC_COLOR_TEMPERATURE)i);
        }

        ImGui::EndTable();
    }
}

void GUI::InfoTab()
{   
    monitorCapabilitiesTable();
    supColorTempsTable();
}


