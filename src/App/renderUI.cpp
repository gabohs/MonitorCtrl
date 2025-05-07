#include "App.h"

PasswordGenerator passGen;

void App::renderUI() 
{
    setStyle::Nord();

    ImGui::SetNextWindowSize({menuSize.x, menuSize.y}, ImGuiCond_Once);
    ImGui::Begin("Password Generator", nullptr, ImGuiWindowFlags_NoTitleBar);

    // Custom Title Bar
    ImGui::BeginGroup();
    ImGui::Text("Random Password Generator!");
    ImGui::SameLine(ImGui::GetWindowWidth() - 35); // Close button

    if (ImGui::SmallButton("X")) 
    {
        glfwSetWindowShouldClose(window_, GLFW_TRUE); // Close the GLFW window
    }
    ImGui::EndGroup();
    ImGui::Separator();

    // BODY 
    
    // Slider
    static int pwdLenght = 10;
    ImGui::Text("Password Lenght: ");

    ImGui::SameLine(ImGui::GetWindowWidth() - 375);
    ImGui::TextColored(Colors::text1, "%d", pwdLenght);
    
    ImGui::SliderInt("##pwdLen", &pwdLenght, 5, 50, "");

    ImGui::Dummy(ImVec2(0.f, 10.f));

    // Checkboxes
    static bool lowerC = true;
    ImGui::Checkbox("Include Lowercase letters", &lowerC);
    
    static bool upperC = true;
    ImGui::Checkbox("Include Uppercase letters", &upperC);

    static bool specialChars = true;
    ImGui::Checkbox("Include Special Characters", &specialChars);

    static bool nums = true;
    ImGui::Checkbox("Include Numbers", &nums);

    ImGui::Dummy(ImVec2(0.f, 10.f));

    // Password
    if ( ImGui::Button("GENERATE") )
    {   
        passGen.generate(pwdLenght, lowerC, upperC, specialChars, nums);  
    }

    ImGui::Text("Your random password: ");
    ImGui::SameLine();
    ImGui::TextColored(Colors::text2, "%s", passGen.getPassword().c_str());

    if ( ImGui::Button("Copy") )
    {
        ImGui::SetClipboardText(passGen.getPassword().c_str());
    }

    ImGui::SameLine();

    if ( ImGui::Button("Clear") )
    {
        passGen.getPassword().clear();
    }

    // FOOTER

    ImGui::Dummy(ImVec2(0.f, 5.f));
    ImGui::Separator();

    ImGui::TextLinkOpenURL("github", "https://github.com/gabohs/PassGen");

    ImGui::End();
}