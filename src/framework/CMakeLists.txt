cmake_minimum_required(VERSION 3.0)
project(framework)

add_library(
    ${PROJECT_NAME} STATIC

    Renderer.cpp
    Texture.cpp
)
