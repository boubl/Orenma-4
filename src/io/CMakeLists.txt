cmake_minimum_required(VERSION 3.0)
project(io)

add_library(
    ${PROJECT_NAME} STATIC

    mouse.cpp
    io.cpp
)