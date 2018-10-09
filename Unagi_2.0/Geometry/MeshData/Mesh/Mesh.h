#pragma once
#include <stddef.h>
#include <vector>
#include "../../../Maths/Vector/Vector3.h"
#include "../../../Maths/Vector/Vector2.h"
#include "../HalfEdgeMesh/HalfEdgeMesh.h"

using namespace Maths;



namespace Geometry
{
    enum GeometryType
    {
        BOX,
        SPHERE,
    };

    struct RendererMeshData
    {
        std::vector<Vector3>        m_VertPos;
        std::vector<Vector3>        m_VertNorm;
        std::vector<Vector3>        m_VertColor;
        std::vector<Vector2>        m_VertTextCoord;
        std::vector<int>            m_Indices;

        void Clear()
        {
            m_VertPos.clear();
            m_VertNorm.clear();
            m_VertColor.clear();
            m_VertTextCoord.clear();
            m_Indices.clear();
        }
    };

    class Mesh
    {
    public:
        Mesh();

        void BuildHalfEdgeMesh();

        int numOfVertex;

        std::vector<Vector3>    m_VertexPos;
        std::vector<std::vector<int>>   m_Faces;
        std::vector<Vector3>    m_VertNorm;

        HalfEdgeMesh    halfEdgeMesh;

        RendererMeshData        renderMeshData;

    protected:
        virtual void    InitMesh();

        virtual void SetVertices();

        virtual void SetNormal();

        virtual void SetIndices();


        bool    isDirty;

        void UpdateRenderMeshData();
    };
}
