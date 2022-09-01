#pragma once

struct GLFWwindow;

#include <string>

class Window{
    private:
        GLFWwindow* m_Window;

    public:
        Window(std::string title, int width, int height);

        bool shouldClose();
        void swapBuffers();

        static void Init();
        static void PollEvents();
};