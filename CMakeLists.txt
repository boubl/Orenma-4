cmake_minimum_required(VERSION 3.0.0)
project(Orenma4 VERSION 0.1.0)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(
    "include/"
    "C:/dev/vcpkg/installed/x64-windows/include/**"
)

add_subdirectory("src")
add_subdirectory("include/imgui")