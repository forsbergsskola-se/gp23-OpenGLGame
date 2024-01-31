
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "mesh.h"
#include "Shader.h"
#include "Material.h"
#include "Triangle.h"
#include "stb_image.h"

using namespace std;

void processInput(GLFWwindow*);



int main() {

    Window window{ 800,600 };

    int width, height, nrChannels;
    unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    // ==================================================================
    // The Real Program starts here
    float red{};
    Vertex vertices[]{
           Vertex{Vector3{-1.0f, -0.5f, 0.0f}},
           Vertex{Vector3{ 0.0f, -0.5f, 0.0f}},
           Vertex{Vector3{-0.5f,  0.5f, 0.0f}},
           Vertex{Vector3{-1.0f, -0.5f, 0.0f}},
           Vertex{Vector3{-0.5f,  0.5f, 0.0f}},
           Vertex{Vector3{-1.0f, 0.5f, 0.0f}}
    };

    Mesh mesh1{ vertices, size(vertices) };

    Vertex vertices2[]{
        Vertex{Vector3{0.0f, -0.5f, 0.0f},Color::red},
        Vertex{Vector3{1.0f, -0.5f, 0.0f},Color::green},
        Vertex{Vector3{0.5f,  0.5f, 0.0f},Color::blue}
    };

    Mesh mesh2{ vertices2, size(vertices) };

    Vertex vertices3[]{
        // positions                           // colors           // texture coords
        Vertex{Vector3{ 0.5f,  0.5f, 0.0f},   Color::red,          Vector2{1.0f, 1.0f}},   // top right
        Vertex{Vector3{ 0.5f, -0.5f, 0.0f},   Color::green,        Vector2{1.0f, 0.0f}},   // bottom right
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},   Color::blue,         Vector2{0.0f, 0.0f}},   // bottom left
        Vertex{Vector3{-0.5f,  0.5f, 0.0f},   Color::yellow,       Vector2{0.0f, 1.0f}}    // top left 
    };

    Mesh mesh3{ vertices3, size(vertices3) };

    // ----- Compile the Vertex Shader on the GPU -------
    Shader vertexShader{"vertexShader.glsl", GL_VERTEX_SHADER};
    

    // ------ Compile the Orange Fragment Shader on the GPU --------
    Shader orangeShader{ "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER };

    // ------ Compile the Yellow Fragment Shader on the GPU --------
    Shader yellowShader{ "yellowFragmentShader.glsl", GL_FRAGMENT_SHADER };


    Shader textureShader{ "textureFragmentShader.glsl", GL_FRAGMENT_SHADER };


    // -------- Create Orange Shader Program (Render Pipeline) ---------
    Material orange(vertexShader, orangeShader);

    // -------- Create Yellow Shader Program (Render Pipeline) ---------
    Material yellow(vertexShader, yellowShader);

    Material texture(vertexShader, textureShader);

    // clean up shaders after they've been linked into a program
    glDeleteShader(orangeShader.shaderID);
    glDeleteShader(yellowShader.shaderID);

    Triangle a(&orange ,&mesh1);
    a.red = 1;
    Triangle b{&yellow, &mesh2 };
    b.red = 0.5;
    Triangle c(&texture, &mesh3);
    c.red = 0.25;

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

        float time = glfwGetTime();
        a.render(time);
        b.render(time);
        c.render(time);

        // present (send the current frame to the computer screen)
        window.GLFWSwap();
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}
