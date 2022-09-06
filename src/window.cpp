#include "window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

Window::Window(std::string title, int width, int height){
    Window::Init();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_Window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
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

void Window::swapBuffers(){
    glfwSwapBuffers(m_Window);
}