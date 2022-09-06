#pragma once

struct GLFWwindow;

#include <string>

class Window{
    private:
        GLFWwindow* m_Window;

        static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void CursorPosCallback(GLFWwindow* window, double posx, double posy);
        static void* selectedWidget;
    public:
        Window(std::string title, int width, int height);

        bool shouldClose();
        void swapBuffers();

        void setUserPointer(void* pointer);

        static void Init();
        static void PollEvents();
};