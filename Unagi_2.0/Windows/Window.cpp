#include "Window.h"
#include <iostream>

namespace UI
{
    Window::Window(int a_width, int a_height, const char * name)
    {
        Init(a_width, a_height, name);
    }
    Window::~Window()
    {
        windowPtr = nullptr;
    }
    int Window::IsWindowClosed()
    {
        return glfwWindowShouldClose(windowPtr);
    }
    void Window::SwapBuffer()
    {
        glfwSwapBuffers(windowPtr);
        glfwPollEvents();
    }
    void Window::Close()
    {
        glfwTerminate();
    }
    void Window::ClearBG()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::Init(int a_width, int a_height, const char * name)
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        windowPtr = glfwCreateWindow(a_width, a_height, name, NULL, NULL);
        
        if(windowPtr==NULL)
        {
            std::cout << "Faild to create window" << std::endl;
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(windowPtr);
        glewInit();
        glEnable(GL_DEPTH_TEST);
    }
}
