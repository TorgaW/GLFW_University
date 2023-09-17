#include "Camera.hpp"

void Camera::UpdateView()
{
    view = glm::mat4(1.0f);
    projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(camera_fov), ScreenUtils::GetWidth() / ScreenUtils::GetHeight(), camera_near_plane, camera_far_plane);
    view = glm::lookAt(camera_position, camera_position + camera_front, camera_up);
}

void Camera::ProcessInput()
{
    const float cameraSpeed = 0.05f; // adjust accordingly
    if (glfwGetKey(WindowUtils::main_window, GLFW_KEY_W) == GLFW_PRESS)
        camera_position += cameraSpeed * camera_front;
    if (glfwGetKey(WindowUtils::main_window, GLFW_KEY_S) == GLFW_PRESS)
        camera_position -= cameraSpeed * camera_front;
    if (glfwGetKey(WindowUtils::main_window, GLFW_KEY_A) == GLFW_PRESS)
        camera_position -= glm::normalize(glm::cross(camera_front, camera_up)) * cameraSpeed;
    if (glfwGetKey(WindowUtils::main_window, GLFW_KEY_D) == GLFW_PRESS)
        camera_position += glm::normalize(glm::cross(camera_front, camera_up)) * cameraSpeed;

    glm::vec3 direction;
    direction.x = cos(glm::radians(MouseInputUtils::mouse_yaw)) * cos(glm::radians(MouseInputUtils::mouse_pitch));
    direction.y = sin(glm::radians(MouseInputUtils::mouse_pitch));
    direction.z = sin(glm::radians(MouseInputUtils::mouse_yaw)) * cos(glm::radians(MouseInputUtils::mouse_pitch));
    camera_front = glm::normalize(direction);
}
