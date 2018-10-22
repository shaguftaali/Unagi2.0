#include "Input.h"

namespace EventSystem
{
    Vector2 Input::mousePosition = Vector2();
    void mouse_cursor_callback(GLFWwindow* window, double xpos, double ypos);

    Input::Input(UI::WindowPtr window, EnvironmentScene::Scene * scene):
    m_Window(window),
    m_ScenePtr(scene)
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
        // Set the background color to the maximum possible value---this value should
        // be far beyond the maximum pick index, since we have at most 2^(8+8+8) = 16,777,216 distinct IDs
        glClearColor(1, 1, 1, 1);

        // Clear any color values currently in the color buffer---we do not want to use these for
        // picking, since they represent, e.g., shading colors rather than pick IDs.
        // Also clear the depth buffer so that we can use it to determine the closest object under the cursor.
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // We want to draw the pick IDs as raw color values; shading functionality
        // like lighting and blending shouldn't interfere.
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glDisable(GL_LIGHTING);
        glDisable(GL_BLEND);

        int pickID = 0;

        for (const auto& node : m_ScenePtr->m_RenderQueue)
        {
            if(node->isPickable)
            {
                
            }
        }

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