#include "window.h"
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <iostream>

Window::Window(std::string title, int width, int height){
    Window::Init();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    std::cout << m_Window << std::endl;
}

void Window::Init(){
    if(!glfwInit()){
        throw std::runtime_error("Failed to initialize GLFW");
    }
    
}

void Window::PollEvents(){
    glfwPollEvents();
}

bool Window::shouldClose(){
    return glfwWindowShouldClose(m_Window);
}