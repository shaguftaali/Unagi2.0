#include "Material.h"
namespace Graphics
{
    Material::Material(ShaderLoader * a_Shader)
    {
        m_ShaderPtr = a_Shader;
    }
    Material::~Material()
    {
        m_ShaderPtr = nullptr;
    }
}