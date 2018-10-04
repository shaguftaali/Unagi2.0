#include "Scene.h"
namespace EnvironmentScene
{
    Scene::Scene(Camera * a_CamPtr):
    camPtr(a_CamPtr)
    {
    }
    void Scene::Render()
    {
        for (auto &node: m_RenderQueue)
        {
            node->UpdateWorldModelMatrix();

            node->Draw(camPtr);
        }
    }
    void Scene::AddToScene(Node * node)
    {
        m_RenderQueue.push_back(node);
    }
}