#pragma once
#include "glad/glad.h"
#include "Shader.h"
class Material
{

public:
    unsigned int ShaderProgram;

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

