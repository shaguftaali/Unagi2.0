#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>

namespace UI
{
    class Window
    {
    public:
        Window(int a_width, int a_height, const char* name);
        ~Window();

        int         IsWindowClosed();
        void        SwapBuffer();
        void        Close();
        void        ClearBG();

    private:
        void        Init(int a_width, int a_height, const char * name);

    private:

    public:
        GLFWwindow * windowPtr;
    };

    typedef std::shared_ptr<Window> WindowPtr;
}
