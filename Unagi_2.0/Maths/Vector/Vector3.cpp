#include "Vector3.h"
#include <cassert>
#include <corecrt_math.h>

namespace Maths
{
    Vector3::Vector3():
    x(0),
    y(0),
    z(0)
    {
    }
    Vector3::Vector3(float a_x, float a_y, float a_z):
    x(a_x),
    y(a_y),
    z(a_z)
    {
    }
    Vector3 Vector3::operator+(const Vector3 & vec)
    {
        return {x+vec.x,y+vec.y,z+vec.z};
    }
    Vector3 Vector3::operator-(const Vector3 & vec)
    {
        return  { x - vec.x,y - vec.y,z - vec.z };
    }
    Vector3 Vector3::operator*(const float scaler)
    {
        return  { x * scaler,y * scaler,z * scaler };
    }
    Vector3 Vector3::operator/(const float scaler)
    {
        assert(scaler > 0 &&"cant divide by zero");
        return  { x / scaler,y / scaler,z / scaler };
    }
    Vector3 Vector3::Normalized()
    {
        float magnitude = Magnitude();
        return Vector3(x,y,z)/ Magnitude();
    }
    float Vector3::Magnitude()
    {
        return sqrtf(x*x+y*y+z*z);
    }
    float Vector3::SqrMaggnitude()
    {
        return (x*x+y*y+z*z);
    }
   /* float Vector3::Magnitude(const Vector3 & vec)
    {
        return sqrtf((vec.x*vec.x + vec.y * vec.y + vec.z * vec.z));
    }
    float Vector3::SqrMaggnitude(const Vector3& vec)
    {
        return (vec.x*vec.x + vec.y * vec.y + vec.z * vec.z);
    }*/
    float Vector3::Distance(const Vector3 & v1, const Vector3 & v2)
    {
        float x = v1.x - v2.x;
        float y = v1.y - v2.y;
        float z = v1.z - v2.z;
   
        return sqrtf(x*x+y*y+z*z);
    }
    float Vector3::DotProduct(const Vector3 & v1, const Vector3 & v2)
    {
        return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);;
    }
    Vector3 Vector3::CrossProduct(const Vector3 & v1, const Vector3 & v2)
    {
        float i = (v1.y*v2.z) - (v2.y*v1.z);
        float j = -(v1.x*v2.z) + (v2.x*v1.z);
        float k = (v1.x*v2.y) - (v2.x*v1.y);
        return {i,j,k};
    }
}
