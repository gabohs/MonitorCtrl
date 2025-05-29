#include <iostream>
#include "App.h"

#ifdef NDEBUG
    #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // hide command prompt when running in release mode
#endif

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
