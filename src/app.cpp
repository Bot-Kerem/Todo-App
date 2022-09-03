#include "app.h"

#include "graphics.h"
#include "widgets/pill.h"

void App::Init(){
    Window::Init();
};

App::App() = default;

void App::run(){
    build();

    Pill pill{};

    while (!window.shouldClose()){
        Window::PollEvents();

        m_MainScene.draw();
        pill.draw();
        window.swapBuffers();
    }
}

void App::build(){
    Graphics::LoadGraphics();
    Graphics::Draw::InitDraw();
}