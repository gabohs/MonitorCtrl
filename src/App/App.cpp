#include "App.h"

App::App() : window_(nullptr) 
{
    menuSize.x = 500;
    menuSize.y = 310;
}

App::~App() 
{
    shutdown();
}

bool App::init() 
{
    if (!initializeGLFW()) 
    {
        return false;
    }
    if (!initializeImGui()) 
    {
        return false;
    }
    return true;
}

bool App::initializeGLFW() 
{
    if (!glfwInit()) 
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);              // hide window border/title
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE); // make glw window transparent

    window_ = glfwCreateWindow(1280, 700, "ImGui Example", nullptr, nullptr);

    if (!window_) 
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window_);
    glfwSwapInterval(1); // Enable vsync
    return true;
}

bool App::initializeImGui() 
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    io.Fonts->AddFontFromFileTTF("src/App/Theme/Font/JETBRAINSMONONL-BOLD.TTF", 15.f);
    if (!ImGui_ImplGlfw_InitForOpenGL(window_, true)) 
    {
        std::cerr << "Failed to initialize ImGui GLFW backend" << std::endl;
        return false;
    }
    if (!ImGui_ImplOpenGL3_Init("#version 330")) 
    {
        std::cerr << "Failed to initialize ImGui OpenGL3 backend" << std::endl;
        return false;   
    }
    return true;
}

void App::run() 
{
    while (!glfwWindowShouldClose(window_)) 
    {
        glfwPollEvents();

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Render UI
        renderUI();

        // Render
        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window_, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.f, 0.f, 0.f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window_);
    }
}

void App::shutdown() 
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    if (window_) 
    {
        glfwDestroyWindow(window_);
        window_ = nullptr;
    }
    glfwTerminate();
}

