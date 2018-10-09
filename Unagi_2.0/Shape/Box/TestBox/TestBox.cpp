#include <GL/glew.h>
#include "TestBox.h"

namespace Geometry
{
   

    TestBox::TestBox(Three_D::Camera a_Cam) :
        Mesh(),
        shader(
            "E:/Shagufta/Workspace/Opengl/Unagi_2.0/Unagi_2.0/ShaderFiles/VertexShader.vs",
            "E:/Shagufta/Workspace/Opengl/Unagi_2.0/Unagi_2.0/ShaderFiles/FragmentShader.fs"
        ),
        cam(a_Cam),
        trans(Three_D::Transform())
    {
        TestBox::InitMesh();
      //  UpdateRenderMeshData();
        numOfVertex = renderMeshData.m_VertPos.size();
        SetData();
    }

    void TestBox::InitMesh()
    {
        SetVertices();
        SetNormal();
        SetIndices();
        /*  numOfVertex = renderMeshData.m_VertPos.size();*/
    }


    void TestBox::Draw()
    {
        shader.Use();
        /*  Matrix4 model = trans.GetModelMatrix();
        Matrix4 view = cam.GetLookMatrix();
        Matrix4 projection = cam.GetProjectionMatrix();
        Matrix4 m1 = model * view;
        Matrix4 m2 = m1 * projection;
        Vector4 v = m2 * Vector4(trans.position, 1);*/

        shader.SetVec3("objectColor", 1.0f, 0.2f, 0.51f);
        shader.SetVec3("lightColor", 1.0f, 1.0f, 1.0f);

        shader.SetMat4("model", trans.GetModelMatrix());
        shader.SetMat4("view", cam.GetLookMatrix());
        shader.SetMat4("projection", cam.GetProjectionMatrix());
        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, numOfVertex, GL_UNSIGNED_INT, 0);
    }

    void TestBox::SetPosition(const Vector3 & pos)
    {
        trans.SetPosition(pos);
    }

    void TestBox::SetScale(const Vector3 & a_scale)
    {
        trans.SetScale(a_scale);
    }

    void TestBox::SetRotation(const Vector3 & rot)
    {
        trans.SetRotation(rot);
    }

    void TestBox::SetData()
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        /*  glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(vecPos.size()) * 3+(sizeof(float)*vecNom.size()*3), nullptr, GL_STATIC_DRAW);

        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)*vecPos.size() * 3, &vecPos[0]);
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(float)*(vecPos.size()) * 3, sizeof(float)*(vecNom.size()) * 3, &vecNom[0]);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*indices.size(), &indices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(sizeof(float)*(vecPos.size()) * 3));
        glEnableVertexAttribArray(1);*/

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

    }

    void TestBox::SetVertices()
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
         renderMeshData.m_VertPos = vecPos1;

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

    void TestBox::SetNormal()
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
        //m_VertNorm = vertNom1;
        renderMeshData.m_VertNorm = vertNom1;
    }

    void TestBox::SetIndices()
    {
        std::vector<int> indices1 = {
            //front
            0,1,2,
            0,2,3,

            //right face
            12,14,13,
            12,15,14,

            //bottom face
            20,21,22,
            20,22,23,

            //top face
            16,17,18,
            16,18,19,

            //left face

            8,10,9,
            8,11,10,

            //back face
            4,6,5,
            4,7,6

        };
        //indices = indices1;
         renderMeshData.m_Indices = indices1;


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

    void TestBox::DeleteBufferData()
    {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }


}

