#include "Engine/Engine.hpp"

int main(void)
{
    if(!Engine::Init())
        return 1;

    CameraManager::CreateCameraAndSetAsActive();
    CameraManager::active_camera->camera_position = {20.0f, 20.0f, 20.0f};
    CameraManager::active_camera->camera_fov = 45.0f;
    auto sun = LightManager::CreatePhongDirectionalLight({1.0f, 1.0f, 1.0f}, EngineColors::white, 1.0f);
    auto d_shader = ShaderManager::CreateDefaultPhongShader();
    // for (size_t i = 0; i < 2; i++)
    // {
    //     for (size_t j = 0; j < 2; j++)
    //     {
    //         auto mesh = MeshManager::CreateMesh("Resources/Models/lenin_statue.obj", "Mesh #1");
    //         mesh->AttachShader(d_shader);
    //         mesh->mesh_position = {i*300.0f, 0.0f, j*300.0f};
    //     }
    // }
    auto mesh = MeshManager::CreateMesh("Resources/Models/parallelogram.obj", "Mesh #1");
    mesh->AttachShader(d_shader);
    mesh->mesh_position = {0.0f, 0.0f, 0.0f};
    mesh->mesh_scale = {10.f, 10.f, 10.f};
    Engine::StartLoop();
    return 0;
}