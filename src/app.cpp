#include "app.h"

#include "graphics.h"

void App::Init(){
    Window::Init();
};

App::App() = default;

void App::run(){
    build();
    Graphics::VertexArray vao;
    Graphics::VertexBuffer vbo;

    while (!window.shouldClose()){
        Window::PollEvents();

        m_MainScene.draw();
        Graphics::Draw::Square(glm::vec2(0.0, 0.5f), glm::vec2(0.2, 0.2f), glm::vec3(0.0, 0.0f, 1.0f));
        window.swapBuffers();
    }
}

void App::build(){
    Graphics::LoadGraphics();
    Graphics::Draw::InitDraw();
}