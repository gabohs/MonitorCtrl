cmake_minimum_required(VERSION 3.10)
project(MyImGuiProject LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Add GLFW from external/
add_subdirectory(external/glfw)

# Set ImGui directory
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)

# List ImGui source files
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_demo.cpp

    
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# Check if ImGui source files exist
foreach(SOURCE_FILE ${IMGUI_SOURCES})
    if(NOT EXISTS ${SOURCE_FILE})
        message(FATAL_ERROR "ImGui source file not found: ${SOURCE_FILE}")
    endif()
endforeach()

# Add ImGui as a static library
add_library(imgui STATIC ${IMGUI_SOURCES})

# Include directories for ImGui
target_include_directories(imgui PUBLIC
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

# Link ImGui dependencies
target_link_libraries(imgui PUBLIC
    glfw
    OpenGL::GL
)

# Create the executable
add_executable(PassGen
    src/main.cpp
    src/App/App.cpp
    src/App/renderUI.cpp
    src/App/Theme/colors.cpp
    src/App/Theme/style.cpp

    src/App/PasswordGenerator/PasswordGenerator.cpp
)

# Link the executable with ImGui and dependencies
target_link_libraries(PassGen PRIVATE imgui)