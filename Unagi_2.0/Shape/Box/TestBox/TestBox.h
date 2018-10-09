#pragma once
#include <stddef.h>
#include <vector>
#include "../../../Maths/Vector/Vector3.h"
#include "../../../Shader/ShaderLoader.h"
#include "../../../Camera/Camera.h"
#include "../../../Transform/Transform.h"
#include "../../../Geometry/MeshData/Mesh/Mesh.h"

using namespace std;
using namespace Maths;
using namespace Shader;
using namespace Geometry;


namespace Geometry
{
    class TestBox:Mesh
    {
    public:

        TestBox(Three_D::Camera a_Cam);

        void Draw();

        void SetPosition(const Vector3& pos);

        void SetScale(const Vector3& a_scale);

        void SetRotation(const Vector3& rot);

        void DeleteBufferData();

    protected:
        void InitMesh() override;

    private:

        void SetData();

        void SetVertices() override;

        void SetNormal() override;

        void SetIndices() override;


    private:
        unsigned int VBO, VAO, EBO;

       /* vector<Vector3> vecPos;

        vector<Vector3> vecNom;

        vector<int> indices;*/

        ShaderLoader shader;

        Three_D::Camera cam;

        Three_D::Transform trans;
    };
}