#pragma once
#include "../../../Geometry/MeshData/Mesh/Mesh.h"

namespace Geometry
{

    class TextBox2:public Mesh
    {
    public:

        TextBox2();

      

        void Draw();

        void SetPosition(const Vector3& pos);

        void SetScale(const Vector3& a_scale);

        void SetRotation(const Vector3& rot);

        void DeleteBufferData();

    protected:
        void InitMesh() override;

    private:

        //void SetData();

        void SetVertices() override;

        void SetNormal() override;

        void SetIndices() override;


    private:
        unsigned int VBO, VAO, EBO;

       

     
    };
}
