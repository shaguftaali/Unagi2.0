#include "ShaderLoader.h"
#include <GL/glew.h>


namespace Shader
{
    ShaderLoader::ShaderLoader(const char * vertexShaderPath, const char * fragmentShadePath)
    {
        std::string vertexCode;
        std::string fragmentCode;

        std::ifstream vShaderFile;
        std::ifstream fShaderFile;

        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try
        {
            vShaderFile.open(vertexShaderPath);
            fShaderFile.open(fragmentShadePath);

            std::stringstream vShaderSteam, fShaderSteam;

            vShaderSteam << vShaderFile.rdbuf();
            fShaderSteam << fShaderFile.rdbuf();

            vShaderFile.close();
            fShaderFile.close();

            vertexCode = vShaderSteam.str();
            fragmentCode = fShaderSteam.str();

        }
        catch (std::ifstream::failure e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }

        const char* vShaderCode = vertexCode.c_str();
        const char* fshaderCode = fragmentCode.c_str();

        unsigned int vertex, fragment;
        int success;
        char infolog[512];

        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        CheckCompilerErrors(vertex, "VERTEX");

        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fshaderCode, NULL);
        glCompileShader(fragment);
        CheckCompilerErrors(fragment, "FRAGMENT");

        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        CheckCompilerErrors(ID, "PROGRAM");

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void ShaderLoader::Use()
    {
        glUseProgram(ID);
    }

    void ShaderLoader::SetBool(const std::string & name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }

    void ShaderLoader::SetInt(const std::string & name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }

    void ShaderLoader::SetFloat(const std::string & name, float value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }

    void ShaderLoader::SetVec3(const std::string & name, float x, float y, float z) const
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }

    void ShaderLoader::SetMat4(const std::string & name, const Maths::Matrix4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE,&mat[0][0]);
    }

    void ShaderLoader::CheckCompilerErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];
        if(type!="PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if(!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
            else
            {
                glGetProgramiv(shader, GL_LINK_STATUS, &success);
                if (!success)
                {
                    glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                    std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
                }
            }
        }
    }

}
