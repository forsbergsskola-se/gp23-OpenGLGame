#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "GameObject.h"
#include "stb_image.h"
#include "Texture.h"
#include <vector>

using namespace std;

void processInput(GLFWwindow*);

int main() {

    Window window{ 800,600 }; // GLFW, GLAD, glViewport

    Texture container{ "container.jpg", GL_TEXTURE0 };
    Texture wall{ "wall.jpg", GL_TEXTURE1 };
    Texture face{ "awesomeface.png", GL_TEXTURE0 };
    Shader vertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER };

    Shader orangeShader{
        "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER
    };

    Shader yellowShader{
        "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER
    };

    Shader textureShader{
        "textureFragmentShader.glsl", GL_FRAGMENT_SHADER
    };


    // -------- Create Shader Program (Render Pipeline) ---------
    Material orange{ vertexShader, orangeShader };
    Material textured{ vertexShader, textureShader };

    GameObject a{ &orange, Mesh::createTriangle()};
    a.red = 1;
    GameObject b{ &orange, Mesh::createTriangle()};
    b.red = 0.5f;
    // GameObject() expects: Mesh*
    // Mesh::createQuad: returns Mesh
    GameObject c{ &textured, Mesh::createQuad(), &wall }; // NEW: use Mesh::createQuad()
    //c.horizontalOffset = -0.5f;
    GameObject d{ &textured, Mesh::createQuad(), &container }; // NEW: use Mesh::createQuad()
    //d.horizontalOffset = +0.5f;

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    //GameObject cube{ &textured, Mesh::createCube(), &wall };
    

    vector<GameObject*> gameObject{};
    for (size_t i = 0; i < size(cubePosition); i++)
    {
        GameObject* newCube = new GameObject(&textured, Mesh::createCube(), &wall);
        newCube->rotation.x = i * 0.1f;
        newCube->rotation.z = i * 0.1f + 0.5f;
        newCube->position = cubePosition[i];
        gameObject.push_back(newCube);

    }
    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!window.shouldClose()) // window -> window.window
    {
        window.processInput();

        window.clear();
        
        c.rotation.x = glfwGetTime();
        c.rotation.y = glfwGetTime() * 0.8f;
        c.rotation.z = glfwGetTime() * 0.6f;
        c.render();

        window.present();
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}