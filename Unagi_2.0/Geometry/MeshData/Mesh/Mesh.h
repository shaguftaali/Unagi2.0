#pragma once
#include <stddef.h>
#include <vector>
#include "../../../Maths/Vector/Vector3.h"
#include "../../../Maths/Vector/Vector2.h"

using namespace Maths;
namespace Geometry
{
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
    protected:
        virtual void    InitMesh()=0;

        virtual void SetVertices()=0;

        virtual void SetNormal()=0;

        virtual void SetIndices()=0;

        RendererMeshData        rendererMeshData;

        bool    isDirty;

        int numOfVertex;

    };
}
