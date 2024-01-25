#pragma once
#include "glad/glad.h"
#include "Shader.h"
class Material
{
    unsigned int ShaderProgram;

public:
	Material(Shader& vertexShader, Shader &fragmentShader) {
        ShaderProgram = glCreateProgram();
        glAttachShader(ShaderProgram, vertexShader.shaderID);
        glAttachShader(ShaderProgram, fragmentShader.shaderID);
        glLinkProgram(ShaderProgram);
	}

    void use() {
        glUseProgram(ShaderProgram);
    }
};

