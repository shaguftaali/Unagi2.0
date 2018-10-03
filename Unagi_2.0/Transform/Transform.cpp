#include "Transform.h"
#include <cmath>

#define PI 3.14159
Three_D::Transform::Transform():
scale(Vector3(1,1,1))
{
    SetModelMatrix();
}

Three_D::Transform::Transform(const Vector3 & a_position):
position(a_position),
scale(Vector3(1, 1, 1))
{
    SetModelMatrix();
}

void Three_D::Transform::SetPosition(const Vector3 & a_position)
{
    isDirty = true;
    position = a_position;
}

void Three_D::Transform::SetRotation(const Vector3 & a_Roatation)
{
    isDirty = true;
    rotation = a_Roatation;
}

void Three_D::Transform::SetScale(const Vector3 & a_scale)
{
    isDirty = true;
    scale = a_scale;
}

void Three_D::Transform::Update()
{
}

Matrix4 Three_D::Transform::GetModelMatrix()
{
    if(isDirty)
    {
        SetModelMatrix();
    }
    return  modelMatrix;
}

void Three_D::Transform::SetModelMatrix()
{
    Vector3 radian = rotation * (PI/ 180.0f);
    const Matrix4 TranslationMat
    {
        Vector4(1,0,0,0),
        Vector4(0,1,0,0),
        Vector4(0,0,1,0),
        Vector4(position.x,position.y,position.z,1)
    };

     Matrix4 ScalMat
    {
        Vector4(scale.x,      0      ,0,0),
        Vector4(0,scale.y,      0,0),
        Vector4(0,      0,scale.z,0),
        Vector4(0,      0,      0,1)
    };

    const Matrix4 X_RotationMat
    {
        Vector4(1,             0,              0, 0),
        Vector4(0,  cos(radian.x), sin(radian.x), 0),
        Vector4(0, -sin(radian.x), cos(radian.x), 0),
        Vector4(0,              0,             0, 1)
    };

    const Matrix4 Y_RotationMat
    {
        Vector4(cos(radian.y), 0, -sin(radian.y), 0),
        Vector4(0, 1,              0, 0),
        Vector4(sin(radian.y), 0,  cos(radian.x), 0),
        Vector4(0, 0,              0, 1)
    };

    const Matrix4 Z_RotationMat
    {
        Vector4(cos(radian.z), sin(radian.z), 0, 0),
        Vector4(-sin(radian.z), cos(radian.z), 0, 0),
        Vector4(0,             0, 1, 0),
        Vector4(0,			    0, 0, 1)
    };

    Matrix4 M1 = ScalMat * X_RotationMat;
    Matrix4 M2 = M1 * Y_RotationMat;
    Matrix4 M3 = M2 * Z_RotationMat;
    modelMatrix = M3 * TranslationMat;
}
