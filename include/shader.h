#pragma once

#include "types.h"

#include <glm/mat4x4.hpp>
#include <glm/mat3x3.hpp>

class Shader
{
    public:
        Shader(const char* vertexPath, const char* fragmentPath);
        Shader(){}

        void constructor(const char* vertexPath, const char* fragmentPath);

        ~Shader();
        void use();
        void setFLoat(const char* name, const float value);
        void setInt(const char* name, const int value);
        void setVec2(const char* name, const Position& value);
        void setVec3(const char* name, const Color& value);
        void setVec4(const char* name, const glm::vec4& value);
        void setMat4(const char* name, const glm::mat4* ptrValue);
        void setMat3(const char* name, const glm::mat3* ptrValue);
        static Shader* currentShader;
        unsigned int program;

    protected:
        int getUniformLocation(const char* varName);
        int status(unsigned int T, unsigned int type);
};