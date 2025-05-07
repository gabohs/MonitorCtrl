#include <iostream>
#include "App/App.h"

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
