#include "Engine/Engine.hpp"

int main(void)
{
    if(!Engine::Init())
        return 1;

    CameraManager::CreateCameraAndSetAsActive();
    // CameraManager::active_camera->camera_fov = 120.0f;
    auto sun = LightManager::CreatePhongDirectionalLight({1.0f, 1.0f, 1.0f}, EngineColors::red, 1.0f);
    auto d_shader = ShaderManager::CreateDefaultPhongShader();
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            auto mesh = MeshManager::CreateMesh("Resources/Models/lenin_statue.obj", "Mesh #1");
            mesh->AttachShader(d_shader);
            mesh->mesh_position = {i*300.0f, 0.0f, j*300.0f};
        }
        
    }
    Engine::StartLoop();
    return 0;
}