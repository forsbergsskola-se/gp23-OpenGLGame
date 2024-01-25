
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "mesh.h"
#include "Shader.h"
#include "Material.h"
#include "Triangle.h"

using namespace std;

void processInput(GLFWwindow*);



int main() {

    Window window{ 800,600 };

    // ==================================================================
    // The Real Program starts here
    float red{};
    float vertices[]{
           -1.0f, -0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f,
           -1.0f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f,
           -1.0f, 0.5f, 0.0f
    };

    Mesh mesh1{vertices, size(vertices)};

    float vertices2[]{
        0.0f, -0.5f, 0.0f,
        1.0f, -0.5f, 0.0f,
        0.5f,  0.5f, 0.0f
    };

    Mesh mesh2{vertices2, size(vertices)};

    // ----- Compile the Vertex Shader on the GPU -------
    Shader vertexShader{"#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0" , GL_VERTEX_SHADER};
    

    // ------ Compile the Orange Fragment Shader on the GPU --------
    Shader orangeShader("#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "} \0", GL_FRAGMENT_SHADER);

    // ------ Compile the Yellow Fragment Shader on the GPU --------
    Shader yellowShader("#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "} \0", GL_FRAGMENT_SHADER);

    // -------- Create Orange Shader Program (Render Pipeline) ---------
    Material orange(vertexShader, orangeShader);

    // -------- Create Yellow Shader Program (Render Pipeline) ---------
    Material yellow(vertexShader, yellowShader);

    // clean up shaders after they've been linked into a program
    glDeleteShader(orangeShader.shaderID);
    glDeleteShader(yellowShader.shaderID);

    Triangle a{ &mesh1, &orange};
    Triangle b{ &mesh2, &yellow };

    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!window.shouldClose())
    {
        // process input (e.g. close window on Esc)
        window.processInput();
        red += 0.001f;
        if (red > 1)
            red -= 1;

        // render (paint the current frame of the game)
        glClearColor(red, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        a.renderer();
        b.renderer();

        // present (send the current frame to the computer screen)
        window.GLFWSwap();
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}
