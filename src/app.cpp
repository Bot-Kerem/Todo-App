#include "app.h"

#include "graphics.h"
#include "widgets/pill.h"
#include <iostream>

void App::Init(){
    Window::Init();
};

App::App() = default;

void App::run(){
    build();
    std::cout << m_MainScene.getPosition().x << std::endl;
    std::cout << m_MainScene.getPosition().y << std::endl;

    Pill pill{Size(200, 50)};
    m_MainScene.Append(&pill);

    while (!window.shouldClose()){
        Window::PollEvents();

        m_MainScene.draw();
        
        window.swapBuffers();
    }
}

void App::build(){
    m_MainScene.update();
    window.setUserPointer(&m_MainScene);
}