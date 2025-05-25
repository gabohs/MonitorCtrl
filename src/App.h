#pragma once

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <iostream>

#include "../Theme/colors.h"
#include "../Theme/style.h"

#include "GUI/GUI.h"

class App
{
private:
    GLFWwindow* window_; 

    bool initializeGLFW();
    bool initializeImGui();
    void shutdown();

    GUI gui;

public:
    App();
    ~App();

    bool init(); // Init the application (GLFW, ImGui)
    void run();
};