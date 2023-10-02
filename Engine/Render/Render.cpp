#include "Render.hpp"

void Render::DrawScreen(float delta_time)
{
    CameraManager::active_camera->UpdateViewAndProjection(delta_time);
    glm::mat4 cam_proj, cam_view;
    CameraManager::active_camera->GetCameraViewAndProjection(&cam_view, &cam_proj);
    auto mesh_pool = MeshManager::GetMeshPool();
    auto light_pool = LightManager::GetPhongLightPool();
    Mesh *t_mesh = nullptr;
    Shader *t_mesh_shader = nullptr;
    for (size_t i = 0; i < mesh_pool->size(); i++)
    {
        if (mesh_pool->at(i)->GetMeshShader() != nullptr)
        {
            // set temp variables
            t_mesh = mesh_pool->at(i);
            t_mesh_shader = t_mesh->GetMeshShader();
            // use mesh shader
            t_mesh_shader->UseShader();
            // set default uniforms
            t_mesh_shader->setMat4("projection", cam_proj);
            t_mesh_shader->setMat4("view", cam_view);

            // light section
            if (t_mesh_shader->shader_type != ShaderType::Unlit)
            {   
                t_mesh_shader->setInt("lights_number", light_pool->size());
                for (int i = 0; i < light_pool->size(); i++)
                {
                    t_mesh_shader->setInt("lights["+std::to_string(i)+"].type", light_pool->at(i)->light_type);
                    t_mesh_shader->setVec3("lights["+std::to_string(i)+"].position", light_pool->at(i)->light_position);
                    t_mesh_shader->setVec3("lights["+std::to_string(i)+"].direction", light_pool->at(i)->light_direction);
                    t_mesh_shader->setVec3("lights["+std::to_string(i)+"].color", light_pool->at(i)->light_color);
                    t_mesh_shader->setFloat("lights["+std::to_string(i)+"].intensity", light_pool->at(i)->light_intensity);
                }
            }

            // calculate model mat4 for object
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::rotate(model, t_mesh->mesh_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::rotate(model, t_mesh->mesh_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::rotate(model, t_mesh->mesh_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::translate(model, t_mesh->mesh_position);
            model = glm::scale(model, t_mesh->mesh_scale);
            // model = glm::scale(model, glm::vec3(0.0f, t_mesh->mesh_scale.y, 0.0f));
            // model = glm::scale(model, glm::vec3(0.0f, 0.0f, t_mesh->mesh_scale.z));

            t_mesh_shader->setMat4("model", model);

            glBindVertexArray(t_mesh->GetVAO());
            glDrawArrays(GL_TRIANGLES, 0, t_mesh->GetIndices());
        }
    }
}