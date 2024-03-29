#pragma once

#include "Mesh.h"
#include "Material.h"
#include "Texture.h"
#include "../Maths/Matrix4x4.h"

class GameObject
{
    const Mesh* mesh;
    Material* material;
    Texture* texture;

public:
    float red;
    Vector3 position = Vector3{ 0, 0, 0 };
    Vector3 rotation = Vector3{ 0, 0, 0 };
    GameObject(Material* _material, const Mesh* _mesh, Texture* _texture = nullptr) {
        mesh = _mesh;
        material = _material;
        texture = _texture;
    }

    void render() {

        material->use();

        int tintLocation = glGetUniformLocation(
            material->ShaderProgram, "tintColor");
        glUniform4f(tintLocation, red, 0, 0, 1);

        Matrix4x4 matTranslation = Matrix4x4::Translation(position);
        Matrix4x4 matRotation = Matrix4x4::Rotation(rotation);

        Matrix4x4 transform = matTranslation * matRotation;

        int transformLocation = glGetUniformLocation(
            material->ShaderProgram, "transform");
        glUniformMatrix4fv(transformLocation, 1, GL_TRUE, &transform.m11);

        int diffuseLocation = glGetUniformLocation(
            material->ShaderProgram, "diffuseTexture");
        glUniform1i(diffuseLocation, 0);

        glActiveTexture(GL_TEXTURE0);

        if (texture != nullptr) {
            glBindTexture(GL_TEXTURE_2D, texture->textureID);
        }
        else {
            glBindTexture(GL_TEXTURE_2D, 0);
        }

        int blendLocation = glGetUniformLocation(
            material->ShaderProgram, "blendTexture");
        glUniform1i(blendLocation, 1);

        mesh->render();
    }
};

// extend the triangle to have data members (fields)
//    - red, green, blue CHECK
//    - pass those data members to your uniform
// in your main function:
//    - pass in red color (1,0,0) for the first CHECK
//    - and green color (0,1,0) for the second CHECK

// result: one red, one green triangle
//         both using the same shader (like in Unity)

// if done early: play around with meshes
// can you make any polygon?
// triangle, square, pentagon, hexagon, ...