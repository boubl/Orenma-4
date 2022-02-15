cmake_minimum_required(VERSION 3.0)
project(imgui)

add_library(
    ${PROJECT_NAME} STATIC
        imgui_demo.cpp
        imgui_draw.cpp
        imgui_tables.cpp
        imgui_widgets.cpp
        imgui.cpp
        backends/imgui_impl_sdlrenderer.cpp
        backends/imgui_impl_sdl.cpp
)