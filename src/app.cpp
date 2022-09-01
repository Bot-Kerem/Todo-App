#include "app.h"
#include "graphics.h"

#include <glad/glad.h>

void App::Init(){
    Window::Init();
};

App::App() = default;

void App::run(){
    build();
    while (!window.shouldClose())
    {
        Window::PollEvents();

        m_MainScene.draw();

        window.swapBuffers();
    }
    
}

void App::build(){
    Graphics::LoadGraphics();
}