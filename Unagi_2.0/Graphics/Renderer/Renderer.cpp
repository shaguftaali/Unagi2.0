#include "Renderer.h"
#include <GL/glew.h>
#include "../../Geometry/MeshData/MeshFilter/MeshFilter.h"

namespace Graphics
{
    Renderer::Renderer(Geometry::Mesh * a_Mesh, Material* a_Material):
    m_MeshPtr(a_Mesh),
    m_Material(*a_Material)
    {
        m_MeshFilterPtr = new Geometry::MeshFilter(a_Mesh);
        
    }
   
    
    Renderer::Renderer():
    m_MeshPtr(nullptr),
    m_Material(nullptr)
    {

    }
   
    Renderer::~Renderer()
    {
        delete m_MeshFilterPtr;
        m_MeshFilterPtr = nullptr;
    }

    void Renderer::SetMesh(Mesh  a_mesh)
    {
        m_MeshPtr = &a_mesh;
        m_Mesh = a_mesh;
    }

    void Renderer::SetMaterial(Material * a_Material)
    {
        m_Material = *a_Material;
    }

    void Renderer::SetMeshFilter()
    {
        if(m_MeshPtr)
        {
            m_MeshFilterPtr = new Geometry::MeshFilter(&m_Mesh);
        }
    }


    void Renderer::Render(Three_D::Camera* m_CameraPtr,  Transform* a_trans)
    {
        m_Material.GetShader()->Use();
        m_MeshFilterPtr->BindVertexGLData();
        m_MeshFilterPtr->BindEBOData();
        m_MeshFilterPtr->UpdateGLData();

        switch (m_RenderMode)
        {
        case RenderMode::LINE:

            break;

        case RenderMode::POINT:

            break;

        case RenderMode::TRIANGLE:

            break;
        }

        m_Material.GetShader()->SetVec3("objectColor", 1.0f, 0.2f, 0.51f);
        m_Material.GetShader()->SetVec3("lightColor", 1.0f, 1.0f, 1.0f);

        m_Material.GetShader()->SetMat4("model", a_trans->GetModelMatrix());
        m_Material.GetShader()->SetMat4("view", m_CameraPtr->GetLookMatrix());
        m_Material.GetShader()->SetMat4("projection", m_CameraPtr->GetProjectionMatrix());

        //m_Material.GetShader()->SetMat4("model", Matrix4::IdentityMat);
        //m_Material.GetShader()->SetMat4("view", Matrix4::IdentityMat);
        //m_Material.GetShader()->SetMat4("projection", Matrix4::IdentityMat);

        glDrawElements(GL_TRIANGLES, m_MeshFilterPtr->GetIndexCount(), GL_UNSIGNED_INT, nullptr);
        m_MeshFilterPtr->UnbindEBOData();
        m_MeshFilterPtr->UnbindGLData();

    }
}
