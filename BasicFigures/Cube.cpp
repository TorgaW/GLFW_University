#include "Cube.hpp"

void Cube::Draw(float delta_time)
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, object_rotation_angels.x, glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, object_rotation_angels.y, glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, object_rotation_angels.z, glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, object_absolute_position);
    if(object_shader_ptr != nullptr)
    {
        object_shader_ptr->setMat4("model", model);
    }
    glBindVertexArray(object_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}