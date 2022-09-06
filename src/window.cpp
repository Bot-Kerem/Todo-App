#include "window.h"
#include "graphics.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

#include "scene.h"

#include <iostream>

void* Window::selectedWidget = nullptr;

Window::Window(std::string title, int width, int height){
    Window::Init();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_Window);

    glfwSetKeyCallback(m_Window, KeyCallback);
    glfwSetCursorPosCallback(m_Window, CursorPosCallback);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    Graphics::Draw::InitDraw();
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

void Window::setUserPointer(void* pointer){
    glfwSetWindowUserPointer(m_Window, pointer);
    selectedWidget = pointer;
}

void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    auto scene = static_cast<Scene*>(glfwGetWindowUserPointer(window));
    if(key == GLFW_KEY_TAB && action == GLFW_PRESS){
        Widget::EditMode = !(Widget::EditMode);
    }
}

void Window::CursorPosCallback(GLFWwindow* window, double posx, double posy){
    auto scene = static_cast<Scene*>(glfwGetWindowUserPointer(window));
    Widget* selectedItem = scene->collide(posx, posy);
    if(selectedItem != nullptr){
        if(selectedWidget != selectedItem){
            static_cast<Widget*>(selectedWidget)->Hover = false;
            selectedWidget = selectedItem;
            selectedItem->Hover = true;
            selectedItem->update();
        }
    }
    else{
        if(selectedWidget != nullptr){
            static_cast<Widget*>(selectedWidget)->Hover = false;
            selectedWidget = nullptr;
            std::cout << "UNHOVERED" << std::endl;
        }
        
    }
}