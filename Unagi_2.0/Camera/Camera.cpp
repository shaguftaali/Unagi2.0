#include "Camera.h"
#include <corecrt_math.h>

namespace Three_D
{
#define PI 3.14159

    Camera::Camera(const Vector3 & a_position, const Vector3 & a_target, const Vector3 & a_up, float a_far, float a_near, float a_FOV):
    position(a_position),
    up(a_up),
    far(a_far),
    near(a_near),
    FOV(a_FOV)
    {
        Vector3 target = a_target;
        eyeDirection = (target - a_position);
        eyeDirection=eyeDirection.Normalized();
        SetLookAtMatrix(position,up);
        SetProjectionMatrix();
    }
    Matrix4 Camera::GetLookMatrix()
    {
      /*  if(isDirty)
        {
            SetLookAtMatrix(position, up);
        }*/
        return viewMatrix;
    }
    Matrix4 Camera::GetProjectionMatrix()
    {
       /* if (isDirty)
        {
            SetProjectionMatrix();
        }*/
        return projectionMatrix;
    }

    void Camera::UpdateMatrixs()
    {
        this;
        if (isDirty)
        {
            SetLookAtMatrix(position, up);
            SetProjectionMatrix();
            isDirty = false;
        }
    }
    
    void Camera::SetPosition(Vector3 a_pos)
    {
        this;
        isDirty = true;
        position = a_pos;
    }

    void Camera::SetUp(Vector3 a_Up)
    {
        isDirty = true;
        up = a_Up;
    }

    void Camera::SetTarget(Vector3 a_target)
    {
        isDirty = true;
        eyeDirection = (a_target - position);
    }


    void Camera::SetLookAtMatrix(Vector3 a_Position,Vector3 a_Up)
    {
        a_Up = Vector3(0, 1, 0);
        Vector3 xAxis = Vector3::CrossProduct(eyeDirection, a_Up);
        xAxis = xAxis.Normalized();

        //Vector3 yAxis = Vector3::CrossProduct(eyeDirection, xAxis);
        Vector3 yAxis = Vector3::CrossProduct(xAxis,eyeDirection);
        yAxis = yAxis.Normalized();

        float ex = -Vector3::DotProduct(xAxis, position);
        float ey = -Vector3::DotProduct(yAxis, position);
        float ez = Vector3::DotProduct(eyeDirection, position);

        viewMatrix = Matrix4(
            Vector4(        xAxis.x,         xAxis.y,         xAxis.z, 0),
            Vector4(        yAxis.x,         yAxis.y,         yAxis.z, 0),
            Vector4(-eyeDirection.x, -eyeDirection.y, -eyeDirection.z, 0),
            Vector4(             ex,              ey,              ez, 1)
        );
    }
    void Camera::SetProjectionMatrix()
    {
        const float radians = (float)FOV*(PI / 180);
        const float A = -(far + near) / (far - near);
        const float B = (-2 * far*near) / (far - near);

        projectionMatrix = Matrix4(
            Vector4(1 / tanf(radians / 2), 0                    , 0,  0),
            Vector4(0                    , 1 / tanf(radians / 2), 0,  0),
            Vector4(0                    , 0                    , A, -1),
            Vector4(0                    , 0                    , B,  0)
        );
    }
}
