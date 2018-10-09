#pragma once
#include "../Mesh/Mesh.h"

namespace Geometry
{
    class MeshFilter
    {
    public:

    private:
        unsigned int     m_VAO;
        unsigned int     m_VBO;
        unsigned int     m_EBO;

        Mesh*   m_MeshPtr;

        int     m_IndexCount;

    public:
        MeshFilter(Mesh* a_Mesh);

        ~MeshFilter();

        void    BindVertexGLData();

        void    UnbindGLData();

        void    BindEBOData();

        void    UnbindEBOData();

        void    UpdateGLData();

        inline int      GetIndexCount() const { return m_IndexCount; }
    private:

        void    SetUpGLData(int numberOVert);

        void    InitializeGLData();


        
    };
}
