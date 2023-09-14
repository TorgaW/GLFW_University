#include "Camera.hpp"

void Camera::UpdateView()
{
    view = glm::mat4(1.0f);
    projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), ScreenUtils::GetWidth() / ScreenUtils::GetHeight(), camera_near_plane, camera_far_plane);
    view = glm::translate(view, camera_position);
}

void Camera::ProcessInput()
{
    const float cameraSpeed = 0.05f; // adjust accordingly
    if (glfwGetKey(WindowUtils::main_window, GLFW_KEY_W) == GLFW_PRESS)
        camera_position += cameraSpeed * cameraFront;
    if (glfwGetKey(WindowUtils::main_window, GLFW_KEY_S) == GLFW_PRESS)
        camera_position -= cameraSpeed * cameraFront;
    if (glfwGetKey(WindowUtils::main_window, GLFW_KEY_A) == GLFW_PRESS)
        camera_position -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(WindowUtils::main_window, GLFW_KEY_D) == GLFW_PRESS)
        camera_position += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}
