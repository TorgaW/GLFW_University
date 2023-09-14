#include "glad.h"
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

#include "ObjectSystem/ObjectSystem.hpp"
#include "Shaders/Shaders.hpp"
#include "Utils/TimeUtils.hpp"
#include "Transformations/Transformations.hpp"
#include "BasicFigures/Cube.hpp"
#include "Utils/ScreenUtils.hpp"
#include "Utils/WindowUtils.hpp"
#include "Camera/Camera.hpp"

int main(void)
{
    ScreenUtils::SetScreenSize(1200, 720);
    
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(ScreenUtils::GetWidth(), ScreenUtils::GetHeight(), "OpenGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* load glad */
    gladLoadGL();

    WindowUtils::main_window = window;

    //depth (enable for 3D)
    glEnable(GL_DEPTH_TEST);

    Shader sh;
    Camera camera_man;
    auto t = ObjectSystem::CreateObject<Cube>("COOOOBE");
    t->SetShader(&sh);

    float deltaTime = 0.0;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        deltaTime = TimeUtils::UpdateDeltaTime();

        // clear screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | /*enable for 3D*/GL_DEPTH_BUFFER_BIT);

        sh.Use();
        camera_man.ProcessInput();
        camera_man.UpdateView();

        // // create transformations
        // glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        // glm::mat4 projection = glm::mat4(1.0f);
        // projection = glm::perspective(glm::radians(45.0f), 1200.0f / 720.0f, 0.1f, 100.0f);
        // view = glm::translate(view, glm::vec3(1.0f, -1.0f, -5.0f));
        // pass transformation matrices to the shader
        sh.setMat4("projection", camera_man.GetProjectionMat4()); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        sh.setMat4("view", camera_man.GetViewMat4());

        // ObjectSystem::UpdateAll(deltaTime);
        ObjectSystem::DrawAll(deltaTime);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}