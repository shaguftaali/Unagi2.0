#include "TestBox2.h"
#include <GL/glew.h>

namespace Geometry
{
    TextBox2::TextBox2(): Mesh()
    {
        TextBox2::InitMesh();
        UpdateRenderMeshData();
        numOfVertex = renderMeshData.m_VertPos.size();
        //SetData();
    }

    void TextBox2::InitMesh()
    {
        SetVertices();
        SetNormal();
        SetIndices();
    }

    void TextBox2::SetVertices()
    {
        float X = 0.2f;
        float Y = 0.2f;
        float Z = 0.5f;

        std::vector<Vector3> vecPos1 = {
            // front
            Vector3(-X, -Y, -Z),  	   //(0)
            Vector3(X, -Y, -Z),      //(1)
            Vector3(X,  Y, -Z),      //(2)
            Vector3(-X,  Y, -Z),  	   //(3)


          //back									   
          Vector3(-X, -Y, Z) ,	   //(4)
          Vector3(X, -Y, Z), 	   //(5)
          Vector3(X,  Y, Z), 	   //(6)
          Vector3(-X,  Y, Z), 	   //(7)

          //left									   
          Vector3(-X, -Y, -Z),	   //(8)
          Vector3(-X, -Y,  Z),	   //(9)
          Vector3(-X,  Y,  Z),   //(10)
          Vector3(-X,  Y, -Z),   //(11)

          //right								   
          Vector3(X,  -Y, -Z),    //(12)
          Vector3(X,   Y, -Z),    //(13)
          Vector3(X,   Y,  Z),    //(14)
          Vector3(X,  -Y,  Z),    //(15)

          //top								   
          Vector3(-X,  Y, -Z), 		   //(16)
          Vector3(X,  Y, -Z),  	   //(17)
          Vector3(X,  Y,  Z),  	   //(18)
          Vector3(-X,  Y,  Z), 		   //(19)

           // bottom
           Vector3(-X, -Y, -Z),      //(20)
           Vector3(-X, -Y,  Z),      //(21)
           Vector3(X, -Y,  Z),      //(22)
           Vector3(X, -Y, -Z),      //(23)
        };
        //vecPos = vecPos1;
        // renderMeshData.m_VertPos = vecPos1;

        std::vector<Vector3> vecPos{
            Vector3(-X,  Y, -Z),
            Vector3(-X, -Y, -Z),
            Vector3(X, -Y, -Z),
            Vector3(X,  Y, -Z),

            Vector3(-X,  Y,  Z),
            Vector3(-X, -Y,  Z),
            Vector3(X, -Y,  Z),
            Vector3(X,  Y,  Z)
        };

        m_VertexPos = vecPos;
    }

    void TextBox2::SetNormal()
    {
        std::vector<Vector3> vertNom1{
            //right
            Vector3(1, 0, 0),  Vector3(1, 0, 0), Vector3(1, 0, 0),
            Vector3(1, 0, 0),  Vector3(1, 0, 0),  Vector3(1,0, 0),

            //front
            Vector3(0, 0,-1),  Vector3(0, 0,-1),  Vector3(0, 0,-1),
            Vector3(0, 0,-1),  Vector3(0, 0,-1),  Vector3(0, 0,-1),

            //left
            Vector3(-1, 0, 0),  Vector3(-1, 0, 0),  Vector3(-1, 0, 0),
            Vector3(-1, 0, 0),  Vector3(-1, 0, 0),  Vector3(-1, 0, 0),

            //bottom
            Vector3(0, 1, 0),  Vector3(0, 1, 0),  Vector3(0, 1, 0),
            Vector3(0, 1, 0),  Vector3(0, 1, 0),  Vector3(0, 1, 0),


            //top
            Vector3(0,-1, 0),  Vector3(0,-1, 0),  Vector3(0,-1, 0),
            Vector3(0,-1, 0),  Vector3(0,-1, 0),  Vector3(0,-1, 0),


            //back
            Vector3(0, 0, 1),  Vector3(0, 0, 1),  Vector3(0, 0, 1),
            Vector3(0, 0, 1),  Vector3(0, 0, 1),  Vector3(0, 0, 1),
        };
        //vecNom = vertNom1;
        m_VertNorm = vertNom1;
    }

    void TextBox2::SetIndices()
    {
       


        std::vector<vector<int>> newIndices{
            { 0,3,2,1 },

        { 4,5,6,7 },

        { 4,0,1,5 },

        { 3,7,6,2 },

        { 0,4,7,3 },

        { 5,1,2,6 }
        };

        m_Faces = newIndices;
    }


   /* void TextBox2::SetData()
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

      
        glBufferData(GL_ARRAY_BUFFER, sizeof(float)*numOfVertex * (3 + 3), nullptr, GL_STATIC_DRAW);

        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)*numOfVertex * 3, &renderMeshData.m_VertPos[0]);
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)*numOfVertex * 3, sizeof(float)*numOfVertex * 3, &renderMeshData.m_VertNorm[0]);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*numOfVertex, &renderMeshData.m_Indices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(sizeof(float)*(numOfVertex) * 3));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

    }*/

}
