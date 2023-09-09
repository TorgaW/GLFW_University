#include "glad.h"
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

#include "ObjectSystem/ObjectSystem.hpp"
#include "Shaders/Shaders.hpp"

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1200, 720, "OpenGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* load glad */
    gladLoadGL();

    Shader sh;
    auto t = ObjectSystem::CreateObject<Object>(vertices, sizeof(vertices) / sizeof(float), "Aboba");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // clear screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        sh.Use();
        t->Draw(0.0f);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}