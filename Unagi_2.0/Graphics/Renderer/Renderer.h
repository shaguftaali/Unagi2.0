#pragma once

#include "../../Geometry/MeshData/HalfEdgeElement/HalfEdgeElement.h"
#include "../../Geometry/MeshData/Mesh/Mesh.h"
#include "../../Geometry/MeshData/MeshFilter/MeshFilter.h"
#include "../Material/Material.h"
#include "../../Camera/Camera.h"
#include "../../Transform/Transform.h"

using namespace Geometry;
using namespace Three_D;
using namespace Maths;

namespace Graphics
{
    enum class RenderMode
    {
        TRIANGLE,
        LINE,
        POINT
    };

    class Renderer
    {
    public:
        Renderer(Mesh* a_Mesh, Material* a_Material);
        Renderer();

        ~Renderer();

        void SetMesh(Mesh a_mesh);

        void SetMaterial(Material* a_Material);

        void SetMeshFilter();

        void    Render(Three_D::Camera* m_CameraPtr, Transform* a_trans);

    private:
        MeshFilter*     m_MeshFilterPtr;
        Mesh*            m_MeshPtr;
        Mesh            m_Mesh;
        RenderMode      m_RenderMode;
        Material        m_Material;
       

    };
}