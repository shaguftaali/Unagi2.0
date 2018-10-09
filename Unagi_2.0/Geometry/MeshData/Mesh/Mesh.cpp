#include "Mesh.h"
namespace Geometry
{
    Mesh::Mesh():
    isDirty(false)
    {
        numOfVertex = 0;
        renderMeshData.Clear();
    }

    void Mesh::BuildHalfEdgeMesh()
    {
        halfEdgeMesh.build(m_Faces, m_VertexPos);
        numOfVertex = m_VertexPos.size();
    }

    void Mesh::InitMesh()
    {
    }

    void Mesh::SetVertices()
    {
    }

    void Mesh::SetNormal()
    {
    }

    void Mesh::SetIndices()
    {
    }

    void Mesh::UpdateRenderMeshData()
    {

        renderMeshData.Clear();
        renderMeshData.m_VertNorm = m_VertNorm;
        auto vertexOffset = 0;

        for (auto &f : m_Faces)
        {
            if(f.size()>3)
            {
                for (unsigned int j=1;j<f.size()-1;j++)
                {
                    renderMeshData.m_Indices.push_back(0 + vertexOffset);
                    renderMeshData.m_Indices.push_back(j + vertexOffset);
                    renderMeshData.m_Indices.push_back(j+1 + vertexOffset);
                }
                vertexOffset += f.size();
            }
        }

        for (auto &f:m_Faces)
        {
            for (unsigned int vertexInd : f)
            {
                renderMeshData.m_VertPos.push_back(m_VertexPos[vertexInd]);
                renderMeshData.m_VertColor.emplace_back(0.25f, 0.25f, 0.25f);
                renderMeshData.m_VertTextCoord.emplace_back(0.0f, 0.0f);
            }
        }
    }
   
}