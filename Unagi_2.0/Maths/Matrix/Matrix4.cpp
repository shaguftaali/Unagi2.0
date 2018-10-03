#include "Matrix4.h"
#include <cassert>

namespace Maths
{
    const Matrix4 Matrix4::IdentityMat = Matrix4(
        Vector4(1,0,0,0),
        Vector4(0,1,0,0),
        Vector4(0,0,1,0),
        Vector4(0,0,0,1)

    );

    Matrix4::Matrix4()
    {
        SetMatrixRow(0, Vector4());
        SetMatrixRow(1, Vector4());
        SetMatrixRow(2, Vector4());
        SetMatrixRow(3, Vector4());
        SetElement();
    }
    Matrix4::Matrix4(const float arg[4][4])
    {
        for (int i=0;i<4;i++)
        {
            for (int j=0;j<4;j++)
            {
                mat[i][j] = arg[i][j];
            }
        }
        SetElement();
    }


    Matrix4::Matrix4(const Vector4 & v1, const Vector4 & v2, const Vector4 & v3, const Vector4 & v4)
    {
        SetMatrixRow(0, v1);
        SetMatrixRow(1, v2);
        SetMatrixRow(2, v3);
        SetMatrixRow(3, v4);
        SetElement();
    }


    Matrix4 Matrix4::Transpose()
    {
        Matrix4 mat4;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                mat4[j][i] = mat[i][j];
            }

        }
        mat4.SetElement();
        return mat4;
    }

    Matrix4 Matrix4::Inverse()
    {
        Matrix4 mat4;
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                mat4[i][j] = mat[j][i];
            }
        }
        mat4.SetElement();
        return mat4;
    }

    Matrix4 Matrix4::operator+(const Matrix4 & mat1)
    {
        Matrix4 mat4;
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                mat4[i][j] = mat[i][j] + mat1[i][j];
            }
        }
        mat4.SetElement();
        return mat4;
    }

    Matrix4 Matrix4::operator-(const Matrix4 & mat1)
    {
        Matrix4 mat4;
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                mat4[i][j] = mat[i][j] - mat1[i][j];
            }
        }
        mat4.SetElement();
        return mat4;
    }

    Matrix4 Matrix4::operator*(const Matrix4 & mat1)
    {
        Matrix4 mat4;
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                for (int k = 0; k<4; k++)
                {
                    mat4[i][j] += mat[i][k] * mat1[k][j];

                }
            }
        }
        mat4.SetElement();
        return mat4;
    }

    Matrix4 Matrix4::operator*(const float scaler)
    {
        Matrix4 mat4;
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                mat4[i][j] = scaler * mat[i][j];
            }
        }
        mat4.SetElement();
        return mat4;
    }

    Vector4 Matrix4::operator*(const Vector4 & vec)
    {
        Vector4 vec4;
        int index = 0;
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                vec4.arr[i] += mat[i][j] * vec.arr[j];
            }
        }
        vec4.x = vec4.arr[0];
        vec4.y = vec4.arr[1];
        vec4.z = vec4.arr[2];
        vec4.w = vec4.arr[3];

        return vec4;
    }

    Matrix4 Matrix4::operator/(const float scaler)
    {
        assert(scaler != 0 && "cant divide matrix by zero");
        Matrix4 mat4;
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                mat4[i][j] = mat[i][j] / scaler;
            }
        }
        mat4.SetElement();
        return mat4;
    }

    float * Matrix4::operator[](int index)
    {
        return mat[index];
    }

    const float * Matrix4::operator[](int index) const
    {
        return mat[index];
    }

    void Matrix4::SetMatrixRow(int row, const Vector4 & vec4)
    {
        mat[row][0] = vec4.x;
        mat[row][1] = vec4.y;
        mat[row][2] = vec4.z;
        mat[row][3] = vec4.w;
    }

    void Matrix4::SetElement()
    {
        int index = 0;
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                elements[index] = mat[i][j];
                index++;
            }
        }
    }
   
}
