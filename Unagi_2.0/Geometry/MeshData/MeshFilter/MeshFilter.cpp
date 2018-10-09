#include "MeshFilter.h"
#include <GL/glew.h>

Geometry::MeshFilter::MeshFilter(Mesh * a_Mesh):
m_MeshPtr(a_Mesh)
{
    InitializeGLData();
}

Geometry::MeshFilter::~MeshFilter()
{
}

void Geometry::MeshFilter::BindVertexGLData()
{
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
}

void Geometry::MeshFilter::UnbindGLData()
{
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
}

void Geometry::MeshFilter::BindEBOData()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
}

void Geometry::MeshFilter::UnbindEBOData()
{
}

void Geometry::MeshFilter::UpdateGLData()
{
}

void Geometry::MeshFilter::SetUpGLData(int numberOfVert)
{
    BindVertexGLData();

    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(3 + 3)*numberOfVert, nullptr, GL_STATIC_DRAW);

    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)*numberOfVert * 3, &(m_MeshPtr->renderMeshData.m_VertPos[0]));
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)*numberOfVert * 3, sizeof(float)*numberOfVert * 3, &(m_MeshPtr->renderMeshData.m_VertNorm[0]));

    BindEBOData();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*m_MeshPtr->renderMeshData.m_Indices.size(), &(m_MeshPtr->renderMeshData.m_Indices[0]),GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(sizeof(float)*numberOfVert * 3));
    glEnableVertexAttribArray(1);

    UnbindEBOData();

    UnbindGLData();

    
}

void Geometry::MeshFilter::InitializeGLData()
{
    m_IndexCount = m_MeshPtr->renderMeshData.m_Indices.size();
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);
    SetUpGLData(m_MeshPtr->numOfVertex);
}
