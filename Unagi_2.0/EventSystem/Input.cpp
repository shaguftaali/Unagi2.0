#include "Input.h"

namespace EventSystem
{
    Vector2 Input::mousePosition = Vector2();
    void mouse_cursor_callback(GLFWwindow* window, double xpos, double ypos);

    Input::Input(UI::WindowPtr window, EnvironmentScene::Scene * scene):
    m_Window(window)
    {
        glfwSetCursorPosCallback(window->windowPtr, mouse_cursor_callback);
        glfwSetInputMode(window->windowPtr, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
  
    bool Input::KeyPressed(std::string key)
    {
        const char c = *key.c_str();
        int keyVal = int(c);
        return glfwGetKey(m_Window->windowPtr, keyVal) == GLFW_PRESS;
    }

    bool Input::IsKeyPressed(int keyVal)
    {
        return glfwGetKey(m_Window->windowPtr,keyVal)==GLFW_PRESS;
    }


    bool Input::KeyReleased(std::string key)
    {
        return false;
    }


    bool Input::IsMouseButtonDown(int button)
    {
        return glfwGetMouseButton(m_Window->windowPtr,button)==GLFW_PRESS;
    }


    bool Input::IsMouseButtonUp(int button)
    {
        return glfwGetMouseButton(m_Window->windowPtr, button) == GLFW_RELEASE;
    }


    void Input::GetHoveredObject(const Vector2 & p, bool transformed)
    {
    }
 
    
    void Input::ProcessInput()
    {
        if(glfwGetKey(m_Window->windowPtr,GLFW_KEY_ESCAPE)==GLFW_PRESS)
        {
            glfwSetWindowShouldClose(m_Window->windowPtr, true);
        }
    }
    void mouse_cursor_callback(GLFWwindow * window, double xpos, double ypos)
    {
        glfwGetCursorPos(window, &xpos, &ypos);
        
        Input::mousePosition.x = xpos;
        Input::mousePosition.y = ypos;
        //Input::mousePosition = Vector2(static_cast<float>(xpos), static_cast<float>(ypos));
    }
}