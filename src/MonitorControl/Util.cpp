#include "Util.h"

#include <highlevelmonitorconfigurationapi.h>

const char* util::colorTempToStr(int value)
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