#include "App.h"

#include "../Theme/Font/JETBRAINSMONONL-BOLD.h"

App::App() : window_(nullptr) 
{ 
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
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE); // make glfw window transparent

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    const int width  = mode->width - 1;
    const int height = mode->height - 1;

    window_ = glfwCreateWindow(width, height, "MonitorCtrl", nullptr, nullptr);

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

    ImFontConfig font_cfg;
    font_cfg.FontDataOwnedByAtlas = false;

    io.Fonts->AddFontFromMemoryTTF(JetBrainsMonoNL, FontSize, 15.0f, &font_cfg);


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
    setStyle::GruvBox_Dark();
    while (!glfwWindowShouldClose(window_)) 
    {
        glfwPollEvents();
        if (glfwGetWindowAttrib(window_, GLFW_ICONIFIED) && glfwGetWindowAttrib(window_, GLFW_FOCUSED))
        {   
            gui.setShouldMinize(false);
            glfwRestoreWindow(window_);
        }

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Render UI
        if (gui.shouldRender())
        {   
            gui.render();
            if (gui.shouldMinimize() || panelUnfocused()) 
                glfwIconifyWindow(window_);  
        }
        else
        {
            glfwSetWindowShouldClose(window_, true);
        }

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

bool App::panelUnfocused()
{   
    if (!window_ || glfwGetWindowAttrib(window_, GLFW_FOCUSED) == 0) // Return false if window is already unfocused
    {
        return false; 
    }    
    else
    {
        const int offset = 20; // so that the gui is not accidentally closed when trying to resize the panel

        bool cursorOutOfPanel = 
            ( (gui.getMousePos().x < (gui.getWindowPos().x - offset)) || (gui.getMousePos().x > (gui.getWindowPos().x + gui.getWindowSize().x + offset)) ) ||
            ( (gui.getMousePos().y < (gui.getWindowPos().y - offset)) || (gui.getMousePos().y > (gui.getWindowPos().y + gui.getWindowSize().y + offset)) );

        if ( (glfwGetMouseButton(window_, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) && (cursorOutOfPanel) )
            return true;
        
        return false;
    }
}
