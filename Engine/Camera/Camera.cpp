#include "Camera.hpp"

void Camera::UpdateViewAndProjection(float delta_time)
{
    camera_view = glm::mat4(1.0f);
    camera_projection = glm::mat4(1.0f);
    camera_projection = glm::perspective(glm::radians(camera_fov), EngineUtil::window_width_f / EngineUtil::window_height_f, camera_near_plane, camera_far_plane);
    camera_view = glm::lookAt(camera_position, camera_position + camera_front, camera_up);
}

void Camera::UpdateInput(float delta_time)
{
    if (glfwGetKey(EngineUtil::glfw_window, GLFW_KEY_W) == GLFW_PRESS)
        camera_position += camera_speed * camera_front;
    if (glfwGetKey(EngineUtil::glfw_window, GLFW_KEY_S) == GLFW_PRESS)
        camera_position -= camera_speed * camera_front;
    if (glfwGetKey(EngineUtil::glfw_window, GLFW_KEY_A) == GLFW_PRESS)
        camera_position -= glm::normalize(glm::cross(camera_front, camera_up)) * camera_speed;
    if (glfwGetKey(EngineUtil::glfw_window, GLFW_KEY_D) == GLFW_PRESS)
        camera_position += glm::normalize(glm::cross(camera_front, camera_up)) * camera_speed;

    glm::vec3 direction;
    direction.x = cos(glm::radians(MouseInputUtil::mouse_yaw)) * cos(glm::radians(MouseInputUtil::mouse_pitch));
    direction.y = sin(glm::radians(MouseInputUtil::mouse_pitch));
    direction.z = sin(glm::radians(MouseInputUtil::mouse_yaw)) * cos(glm::radians(MouseInputUtil::mouse_pitch));
    camera_front = glm::normalize(direction);
}
