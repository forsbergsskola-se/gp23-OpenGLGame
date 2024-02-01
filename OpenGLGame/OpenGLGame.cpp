
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "mesh.h"
#include "Shader.h"
#include "Material.h"
#include "Triangle.h"
#include "stb_image.h"
#include "Texture.h"

using namespace std;

void processInput(GLFWwindow*);


int main() {

    Window window{ 800,600 };

    int width, height, nrChannels;

    //Generate container image
    Texture container{ "container.jpg", GL_TEXTURE0 };
    
    //Generate wall image
    Texture wall{ "wall.jpg", GL_TEXTURE1 };

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

        Vertex{Vector3{-0.5f,  0.5f, 0.0f},   Color::yellow,       Vector2{0.0f, 1.0f}},     // top left
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},   Color::blue,         Vector2{0.0f, 0.0f}},
        Vertex{Vector3{ 0.5f,  0.5f, 0.0f},   Color::red,          Vector2{1.0f, 1.0f}},
    };

    Mesh mesh3{ vertices3, size(vertices3) };

    // ----- Compile the Vertex Shader on the GPU -------
    Shader vertexShader{"vertexShader.glsl", GL_VERTEX_SHADER};
    

    // ------ Compile the Orange Fragment Shader on the GPU --------
   // Shader orangeShader{"orangeFragmentShader.glsl", GL_FRAGMENT_SHADER };

    // ------ Compile the Yellow Fragment Shader on the GPU --------
   // Shader yellowShader{"yellowFragmentShader.glsl", GL_FRAGMENT_SHADER };


    Shader textureShader{"textureFragmentShader.glsl", GL_FRAGMENT_SHADER };


    // -------- Create Orange Shader Program (Render Pipeline) ---------
    //Material orange(vertexShader, orangeShader);

    // -------- Create Yellow Shader Program (Render Pipeline) ---------
    //Material yellow(vertexShader, yellowShader);

    Material texture(vertexShader, textureShader);

    // clean up shaders after they've been linked into a program
    //glDeleteShader(orangeShader.shaderID);
    //glDeleteShader(yellowShader.shaderID);

    //Triangle a(&orange ,&mesh1);
    //a.red = 1;
    //Triangle b{&yellow, &mesh2 };
    //b.red = 0.5;
    Triangle c(&texture, &mesh3, &wall);
    c.horizontalOffset = -0.5f;
    Triangle d(&texture, &mesh3, &container);
    d.horizontalOffset = +0.5f;



    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!window.shouldClose())
    {
        // process input (e.g. close window on Esc)
        window.processInput();
        
        red = 0.5;
        //if (red > 1)
        //    red -= 1;

        // render (paint the current frame of the game)
        glClearColor(red, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //a.render();
        //b.render();
        c.render();
        d.render();

        // present (send the current frame to the computer screen)
        window.GLFWSwap();
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}
