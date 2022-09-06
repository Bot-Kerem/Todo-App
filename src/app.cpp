#include "app.h"

#include "graphics.h"
#include "widgets/pill.h"

void App::Init(){
    Window::Init();
};

App::App() = default;

void App::run(){
    build();

    Pill pill{Size(200, 50)};
    m_MainScene.Append(&pill);

    while (!window.shouldClose()){
        Window::PollEvents();

        m_MainScene.draw();
        
        window.swapBuffers();
    }
}

void App::build(){
    Graphics::Draw::InitDraw();
}