#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "..\Maths/Matrix/Matrix4.h"


namespace Shader
{
    class ShaderLoader
    {
    public:

        unsigned int ID;

        ShaderLoader(const char* vertexShaderPath, const char* fragmentShadePath);

        void Use();

        void SetBool(const std::string &name, bool value) const;

        void SetInt(const std::string &name, int value) const;

        void SetFloat(const std::string &name, float value) const;

        //void setMat4(const std::string &name, const Matrix4 &mat) const;

        void SetVec3(const std::string &name, float x, float y, float z) const;
        void SetMat4(const std::string &name, const Maths::Matrix4 &mat) const;

    private:
        void CheckCompilerErrors(unsigned int shader, std::string type);
    };
}
