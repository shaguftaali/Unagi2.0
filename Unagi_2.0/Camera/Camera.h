#pragma once
#include "../Maths/Vector/Vector3.h"
#include "../Maths/Matrix/Matrix4.h"

using namespace Maths;

namespace Three_D
{
    class Camera
    {
    public:
        
        Camera(
            const Vector3& a_position,
            const Vector3& a_target,
            const Vector3& a_up,
            float a_far,
            float a_near,
            float a_FOV
        );

        Matrix4 GetLookMatrix();
        Matrix4 GetProjectionMatrix();

    private:
        void SetLookAtMatrix(Vector3 a_Position, Vector3 a_Up);
        void SetProjectionMatrix();

    private:
        Vector3 position;
        Vector3 eyeDirection;
        Vector3 up;

        float far;
        float near;
        float FOV;

        bool isDirty;

        Matrix4 viewMatrix;
        Matrix4 projectionMatrix;
    };
}
