#pragma once
#include "../Maths/Vector/Vector3.h"
#include "../Maths/Matrix/Matrix4.h"

using namespace Maths;

namespace Three_D
{
    class Transform
    {
    public:
        Transform();
        Transform(const Vector3& position);

        void SetPosition(const Vector3& a_position);
        void SetRotation(const Vector3& a_Roatation);
        void SetScale(const Vector3& a_scale);
        void Update();
        Matrix4 GetModelMatrix();

    public:
        Vector3 position;
        Vector3 rotation;
        Vector3 scale;



    private:

        void SetModelMatrix();

    private:
        bool isDirty;
        Matrix4 modelMatrix; 
       
    };
}
