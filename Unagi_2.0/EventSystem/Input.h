#pragma once
#include "../Windows/Window.h"
#include "../Scene/Scene.h"

namespace EventSystem
{
    class Input
    {
    public:

        Input(UI::WindowPtr window, EnvironmentScene::Scene* scene);

        bool        KeyPressed(std::string key);
        bool        IsKeyPressed(int keyVal);
        bool        KeyReleased(std::string key);

        bool        IsMouseButtonDown(int button);
        bool        IsMouseButtonUp(int button);

        void        GetHoveredObject(const Vector2& p,bool transformed);

        static  Vector2 mousePosition;




    private:
        void                ProcessInput();

        UI::WindowPtr       m_Window;
        

    };
}
