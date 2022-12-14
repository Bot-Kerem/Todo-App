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

    Pill pill2{Size(300, 100)};
    m_MainScene.Append(&pill2);
    pill.setPosition(glm::vec2{500, 200});
    pill.update();

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
