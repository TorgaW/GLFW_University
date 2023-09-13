#include "Transformations.hpp"

void Transformations::Translate(glm::vec3 translate_vector)
{
    //set identity matrix
    current_transform = glm::mat4(1.0f);
    current_transform = glm::translate(current_transform, translate_vector);
}

void Transformations::Rotate(float angle, glm::vec3 axis)
{
    current_transform = glm::rotate(current_transform, angle, axis);
}

void Transformations::Scale(glm::vec3 scale_factor)
{
    current_scale = scale_factor;
}
