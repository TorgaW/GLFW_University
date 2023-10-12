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

    std::vector<float> vbo_data = {
        0.5f, -1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.230769f, 0.846154f,
        -0.5f, 1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.769229f, 0.153846f,
        -1.5f, -1.0f, 0.0f,  0.0f, 0.0f, 1.0f,   0.999999f, 0.999999f,

        0.5f, -1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.230769f, 0.846154f,
        1.5f, 1.0f, 0.0f,    0.0f, 0.0f, 1.0f,   -0.000001f, 0.000001f,
        -0.5f, 1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.769229f, 0.153846f,
    };

    auto mesh = MeshManager::CreateMesh(vbo_data, 6, "Mesh #1");
    mesh->AttachShader(d_shader);
    mesh->mesh_position = {0.0f, 0.0f, 0.0f};
    mesh->mesh_rotation = {0.0f, 0.0f, 180.0f};
    mesh->mesh_scale = {5.f, 5.f, 5.f}; 
    Engine::StartLoop();
    return 0;
}