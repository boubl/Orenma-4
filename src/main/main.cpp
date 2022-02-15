
#include <stdio.h>
#include <SDL.h>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_sdlrenderer.h>
#include <imgui/backends/imgui_impl_sdl.h>
#include "Editor/Editor.h"
#include <SDL_image.h>
#include "Framework/Texture.h"
#include "Framework/Renderer.h"

// Main code
int main(int, char**)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }
    
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        SDL_Log("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return -1;
    }

    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow("Orenma 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);

    Renderer::Init(window);
    
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForSDLRenderer(window, Renderer::renderer);
    ImGui_ImplSDLRenderer_Init(Renderer::renderer);

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 0.00f);

    Editor editor("Orenma 4");
    editor.Init();
    
    // Main loop
    bool done = false;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                done = true;
            editor.Events(&event);
        }

        editor.Update();
        SDL_SetWindowTitle(window, editor.Window_name.c_str());

        // Start the Dear ImGui frame
        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow();

        SDL_SetRenderDrawColor(Renderer::renderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
        
        Renderer::Begin();
        editor.Draw();
        // Rendering
        ImGui::Render();
        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
        Renderer::End();
    }

    editor.Close();

    // Cleanup
    ImGui_ImplSDLRenderer_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    Renderer::Close();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
