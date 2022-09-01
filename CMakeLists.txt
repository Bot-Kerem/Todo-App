cmake_minimum_required(VERSION 3.23)

find_package(glfw3 REQUIRED)

project(todoapp)

set(PROJECT_SOURCES 
        src/main.cpp
        src/app.cpp
        src/window.cpp
        )

include_directories(include)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} glfw)
