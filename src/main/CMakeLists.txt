cmake_minimum_required(VERSION 3.0)
project(main)

add_executable(${PROJECT_NAME} main.cpp)
# personal librairies
target_link_libraries(${PROJECT_NAME} PUBLIC editor)
target_link_libraries(${PROJECT_NAME} PUBLIC framework)
target_link_libraries(${PROJECT_NAME} PUBLIC io)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_LIBRARIES})

# external librairies
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2_image)
