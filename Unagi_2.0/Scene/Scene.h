#pragma once
#include "../Camera/Camera.h"
#include <stddef.h>
#include <vector>
#include "../Graphics/Node/Node.h"

using namespace Three_D;
using namespace std;
using namespace Graphics;
namespace EnvironmentScene
{
    class Scene
    {
    public:
        Scene(Camera* a_CamPtr);

        void    Render();
        void    AddToScene(Node* node);
    private:
        Camera * camPtr;
        vector<Node*>   m_RenderQueue;
    };
}