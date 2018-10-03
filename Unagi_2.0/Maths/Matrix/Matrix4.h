#pragma once
#include "../Vector/Vector4.h"

namespace Maths
{
    class Matrix4
    {
    public:
        Matrix4();
        Matrix4(const float arg[4][4]);
        Matrix4(const Vector4& v1, const Vector4& v2, const Vector4& v3, const Vector4& v4);

       Matrix4 Transpose();

       Matrix4 Inverse();

       static const Matrix4 IdentityMat;

       Matrix4 operator +(const Matrix4& mat1);

       Matrix4 operator -(const Matrix4& mat1);

       Matrix4 operator *(const Matrix4& mat1);

       Matrix4 operator *(const float scaler);

        Vector4 operator *(const Vector4& vec);

       Matrix4 operator /(const float scaler);

       float* operator[](int index);

       const float* operator[](int index)const;

    public:
       float elements[4 * 4];

    private:
        float mat[4][4];
        void SetMatrixRow(int row, const Vector4& vec4);
        void SetElement();

    };
}
