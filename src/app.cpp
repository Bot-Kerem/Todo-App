#include "app.h"

void App::Init(){
    Window::Init();
};

App::App() = default;

void App::run(){
    while (!window.shouldClose())
    {
        Window::PollEvents();
    }
    
}