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
        MessageBox(NULL, TEXT("Failed to Init Application!"), TEXT("Error"), MB_OK | MB_ICONERROR);
        return -1;
    }

    app.run();

    return 0;
}
