#include "Node.h"
#include "../../Shape/Box/TestBox2/TestBox2.h"

namespace Graphics
{
   

    Node::Node(Material * a_Mat, GeometryType a_Type):
    m_Mat(a_Mat)
    {
        //Renderer r(GetMesh(a_Type), m_Mat);
       //m_Renderer=r;
        m_Renderer.SetMaterial(a_Mat);
        m_Renderer.SetMesh(GetMesh(GeometryType::BOX));
        m_Renderer.SetMeshFilter();
    }
    void Node::Draw(Camera* camPtr)
    {
        m_Renderer.Render(camPtr,&m_trans);
    }

    void Node::UpdateWorldModelMatrix()
    {
    }

    void Node::SetPosition(const Vector3 & a_Pos)
    {
        m_trans.SetPosition(a_Pos);
    }

    void Node::SetScale(const Vector3 & a_Scale)
    {
        m_trans.SetScale(a_Scale);
    }
  
   

    Mesh  Node::GetMesh(GeometryType a_MeshType)
    {
       TextBox2 boxMesh;
       return (boxMesh);
        //return &Renderer(&boxMesh, m_Mat);
    }
   
}
