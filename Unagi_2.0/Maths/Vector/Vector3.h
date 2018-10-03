#pragma once

namespace  Maths
{
    class  Vector3
    {
    public:
        float x;
        float y;
        float z;

        Vector3();

        Vector3(float a_x, float a_y, float a_z);

        Vector3 operator +(const Vector3& vec);
        Vector3 operator -(const Vector3& vec);
        Vector3 operator *(const float scaler);
        Vector3 operator /(const float scaler);

        Vector3 Normalized();
        float   Magnitude();
        float   SqrMaggnitude();
        
        //static  float   Magnitude(const Vector3& vec);
        ////static  float   SqrMaggnitude(const Vector3& vec);
        static float   Distance(const Vector3& v1, const Vector3& v2);
        static float   DotProduct(const Vector3& v1, const Vector3& v2);
        static Vector3  CrossProduct(const Vector3& v1, const Vector3& v2);



    };
}