#pragma once
#include "../../Transform/Transform.h"
#include "../Renderer/Renderer.h"

using namespace Three_D;

namespace Graphics
{
    class Node
    {

    public:

        Node(Material* a_Mat,GeometryType a_Type);
        void Draw(Camera* camPtr);
        void UpdateWorldModelMatrix();


        void        SetPosition(const Vector3& a_Pos);

        void        SetScale(const Vector3& a_Scale);

        //void        SetRotation()

    public:
        Renderer m_Renderer;
        Material*    m_Mat;
        bool    isPickable; 
        static int uID;
    protected:
        Transform   m_trans;

    protected:
       

        Mesh GetMesh(GeometryType a_MeshType);

        
    };
}
