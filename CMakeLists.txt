cmake_minimum_required(VERSION 3.23)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

project(todoapp)

set(PROJECT_SOURCES 
        src/main.cpp
        src/app.cpp
        src/window.cpp
        src/theme.cpp
        src/node.cpp
        src/scene.cpp
        src/graphics.cpp
        src/glad.c
        src/file.cpp
        src/shader.cpp
        #---------WIDGETS---------#
        src/widgets/widget.cpp
        src/widgets/pill.cpp
        #---------WIDGETS---------#
        )

include_directories(include)

message(${PROJECT_SOURCES})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} glfw glm)
