#pragma once

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>

#include "Theme/colors.h"
#include "Theme/style.h"

#include "PasswordGenerator/PasswordGenerator.h"

class App
{
private:
    GLFWwindow* window_; 
    ImVec2 menuSize; // X and Y positions for the ImGui menu

    bool initializeGLFW();
    bool initializeImGui();
    void renderUI(); // defined in renderUI.cpp
    void shutdown();

public:
    App();
    ~App();

    bool init(); // Init the application (GLFW, ImGui)
    void run();
};