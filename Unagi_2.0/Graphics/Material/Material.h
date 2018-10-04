#pragma once
#include "../../Shader/ShaderLoader.h"

using namespace Shader;

namespace Graphics
{
    class Material
    {
    public:
        Material(ShaderLoader* a_Shader);
        ~Material();

        inline ShaderLoader*    GetShader() { return m_ShaderPtr; }

    private:
        ShaderLoader * m_ShaderPtr;

    };
}
