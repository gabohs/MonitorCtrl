#include <iostream>
#include "App.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main()
{
    App app;
    if (!app.init())
    {
        std::cerr << "Failed to init application" << std::endl;
        return -1;
    }

    app.run();

    return 0;
}
