#pragma once
#include "glad/glad.h"

class Shader
{
public:
    unsigned int shaderID;
	Shader(const char* source, int shaderType) { // when constructed: load shader on GPU
        shaderID = glCreateShader(shaderType);
        glShaderSource(shaderID, 1, &source, nullptr);
        glCompileShader(shaderID);
	}
    Shader(const Shader&) = delete; // To avoid being cloned

    ~Shader() { // when destructed: delete the shader from GPU // Copy constructor
        glDeleteShader(shaderID);
    }
    // glDeleteShader(vertexShader.shaderID);
};

