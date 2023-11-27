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
            #ifdef PHONG
            // set temp variables
            t_mesh = mesh_pool->at(i);
            t_mesh_shader = t_mesh->GetMeshShader();
            // use mesh shader
            t_mesh_shader->UseShader();
            t_mesh_shader->setInt("tex_0", 2);
            // set default uniforms
            t_mesh_shader->setMat4("projection", cam_proj);
            t_mesh_shader->setMat4("view", cam_view);
            t_mesh_shader->setVec3("viewPosition", CameraManager::active_camera->camera_position);

            // light section
            if (t_mesh_shader->shader_type != ShaderType::Unlit)
            {   
                t_mesh_shader->setInt("lights_number", light_pool.size());
                for (int i = 0; i < light_pool.size(); i++)
                {
                    t_mesh_shader->setInt("lights["+std::to_string(i)+"].type", light_pool[i]->light_type);
                    t_mesh_shader->setVec3("lights["+std::to_string(i)+"].position", light_pool[i]->light_position);
                    t_mesh_shader->setVec3("lights["+std::to_string(i)+"].direction", light_pool[i]->light_direction);
                    t_mesh_shader->setVec3("lights["+std::to_string(i)+"].color", light_pool[i]->light_color);
                    t_mesh_shader->setFloat("lights["+std::to_string(i)+"].intensity", light_pool[i]->light_intensity);
                }
            }
            #endif
            #ifdef PBR
            // set temp variables
            t_mesh = mesh_pool->at(i);
            t_mesh_shader = t_mesh->material->mat_shader;
            // use mesh shader
            t_mesh_shader->UseShader();
            t_mesh_shader->setInt("t_albedo", 2);
            t_mesh_shader->setInt("t_normal_map", 3);
            t_mesh_shader->setInt("t_metallic_map", 4);
            t_mesh_shader->setInt("t_roughness_map", 5);
            t_mesh_shader->setInt("t_ao_map", 6);
            // set default uniforms
            t_mesh_shader->setMat4("projection", cam_proj);
            t_mesh_shader->setMat4("view", cam_view);
            t_mesh_shader->setVec3("camPos", CameraManager::active_camera->camera_position);
            #endif
            // calculate model mat4 for object
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::rotate(model, glm::radians(t_mesh->mesh_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::rotate(model, glm::radians(t_mesh->mesh_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::rotate(model, glm::radians(t_mesh->mesh_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::translate(model, t_mesh->mesh_position);
            model = glm::scale(model, t_mesh->mesh_scale);
            // model = glm::scale(model, glm::vec3(0.0f, t_mesh->mesh_scale.y, 0.0f));
            // model = glm::scale(model, glm::vec3(0.0f, 0.0f, t_mesh->mesh_scale.z));
            
            t_mesh_shader->setMat4("model", model);

            #ifdef PHONG
            glActiveTexture(GL_TEXTURE2);
            glBindTexture(GL_TEXTURE_2D, t_mesh->mesh_texture->gl_bitmap_index);
            #endif

            #ifdef PBR
            t_mesh_shader->setMat3("normal_matrix", glm::transpose(glm::inverse(glm::mat3(model))));

            t_mesh_shader->setVec3("lightPositions[0]", glm::vec3(10.0f, 10.0f, 0.0f)); //TODO LIGHT
            t_mesh_shader->setVec3("lightColors[0]", glm::vec3(150.0f));

            t_mesh_shader->setFloat("p_albedo_intensity", t_mesh->material->t_albedo_intensity);
            t_mesh_shader->setFloat("p_normal_map_intensity", t_mesh->material->t_normal_map_intensity);
            t_mesh_shader->setFloat("p_metallic_intensity", t_mesh->material->t_metallic_map_intensity);
            t_mesh_shader->setFloat("p_roughness_intensity", t_mesh->material->t_roughness_map_intensity);
            t_mesh_shader->setFloat("p_ao_intensity", t_mesh->material->t_ao_map_intensity);

            t_mesh->material->SetShaderTexturesDuringRender();
            #endif

            glBindVertexArray(t_mesh->GetVAO());
            glDrawArrays(GL_TRIANGLES, 0, t_mesh->GetIndices());
        }
    }
}