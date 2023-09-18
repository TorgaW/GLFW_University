#include "Render.hpp"

void Render::DrawScreen(float delta_time)
{
    CameraManager::active_camera->UpdateViewAndProjection(delta_time);
    glm::mat4 cam_proj, cam_view;
    CameraManager::active_camera->GetCameraViewAndProjection(&cam_view, &cam_proj);
    auto mesh_pool = MeshManager::GetMeshPool();
    Mesh *t_mesh = nullptr;
    Shader *t_mesh_shader = nullptr;
    for (size_t i = 0; i < mesh_pool->size(); i++)
    {
        if(mesh_pool->at(i)->GetMeshShader() != nullptr)
        {   
            //set temp variables
            t_mesh = mesh_pool->at(i);
            t_mesh_shader = t_mesh->GetMeshShader();
            //use mesh shader
            t_mesh_shader->UseShader();
            //set default uniforms
            t_mesh_shader->setMat4("projection", cam_proj);
            t_mesh_shader->setMat4("view", cam_view);
            
            //calculate model mat4 for object
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::rotate(model, t_mesh->mesh_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::rotate(model, t_mesh->mesh_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::rotate(model, t_mesh->mesh_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::translate(model, t_mesh->mesh_position);
            
            t_mesh_shader->setMat4("model", model);

            glBindVertexArray(t_mesh->GetVAO());
            glDrawArrays(GL_TRIANGLES, 0, t_mesh->GetIndices());
        }
    }
    
}