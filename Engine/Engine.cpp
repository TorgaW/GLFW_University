#include "Engine.hpp"
/**
 * @brief Public functions section
 */

/**
 * @brief Inits Engine with default window's size. (see macros ENGINE_DEFAULT_WINDOW_SIZE_X and ENGINE_DEFAULT_WINDOW_SIZE_Y)
 *
 * @return true on success,
 * @return false otherwise
 */
bool Engine::Init()
{
    return EngineInit(ENGINE_DEFAULT_SCREEN_SIZE_X, ENGINE_DEFAULT_SCREEN_SIZE_Y);
}

/**
 * @brief Inits Engine with provided window's size.
 *
 * @param screen_size_x width in pixels
 * @param screen_size_y height in pixels
 * @return true on success,
 * @return false otherwise
 */
bool Engine::Init(uint16_t screen_size_x, uint16_t screen_size_y)
{
    if (screen_size_x < 100 || screen_size_y < 100)
    {
        std::cout << "Window is too small!\n";
        return false;
    }
    return EngineInit(screen_size_x, screen_size_y);
}

/**
 * @brief Starts Engine rendering
 *
 */
void Engine::StartLoop()
{
    while (!glfwWindowShouldClose(EngineUtil::glfw_window))
    {
        // check for termination flag
        if (engine_terminate_flag || glfwGetKey(EngineUtil::glfw_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            EngineTerminate();
            break;
        }

        // update delta time
        TimeUtil::UpdateTime();

        //update mouse input
        MouseInputUtil::UpdateMouseInput();

        // update camera input
        CameraManager::active_camera->UpdateInput(TimeUtil::GetDeltaTime());

        // clear screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // rendering
        Render::DrawScreen(TimeUtil::GetDeltaTime());

        /* Swap front and back buffers */
        glfwSwapBuffers(EngineUtil::glfw_window);

        /* Poll for and process events */
        glfwPollEvents();
    }
}

/**
 *  Private functions section
 */

/**
 * @brief Inits engine with window's size variables
 *
 * @param screen_size_x width in pixels
 * @param screen_size_y height in pixels
 * @return true if successfully created window,
 * @return false otherwise
 */
bool Engine::EngineInit(uint16_t screen_size_x, uint16_t screen_size_y)
{
    if (!glfwInit())
        return false;

    EngineUtil::glfw_window = glfwCreateWindow(screen_size_x, screen_size_y, "OpenGL 3D View", nullptr, nullptr);
    if (EngineUtil::glfw_window == nullptr)
    {
        std::cout << "Failed to create window.\n";
        glfwTerminate();
        return false;
    }
    EngineUtil::window_width = screen_size_x;
    EngineUtil::window_height = screen_size_y;
    EngineUtil::window_width_f = screen_size_x;
    EngineUtil::window_height_f = screen_size_y;
    glfwMakeContextCurrent(EngineUtil::glfw_window);
    glfwSetInputMode(EngineUtil::glfw_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    gladLoadGL();
    glEnable(GL_DEPTH_TEST);
    return true;
}

// Close engine
void Engine::EngineTerminate()
{
    glfwTerminate();
}
