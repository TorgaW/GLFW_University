#include "Engine/Engine.hpp"

int main(void)
{
    if(!Engine::Init())
        return 1;

    CameraManager::CreateCameraAndSetAsActive();
    CameraManager::active_camera->camera_position = {10.0f, 20.0f, 25.0f};
    CameraManager::active_camera->camera_fov = 50.0f;
    auto sun = LightManager::CreatePhongDirectionalLight({1.0f, 1.0f, 1.0f}, EngineColors::white, 1.0f);
    auto d_shader = ShaderManager::CreateDefaultPhongShader();

    std::vector<float> vbo_data = {
        -0.5f, 0.f, -1.f, -0.f, -1.f, -0.f, 0.287935f, 0.856032f,
        0.5f, 0.f, 1.f, -0.f, -1.f, -0.f, 0.f, 0.640081f,
        -1.5f, 0.f, 1.f, -0.f, -1.f, -0.f, 0.287935f, 0.496114f,

        -0.5f, 0.f, -1.f, -0.8422f, 0.3369f, -0.4211f, 0.212468f, 0.339446f,
        -1.5f, 0.f, 1.f, -0.8422f, 0.3369f, -0.4211f, 0.f, 0.048931f,
        0.f, 2.5f, 0.f, -0.8422f, 0.3369f, -0.4211f, 0.493695f, 0.f,

        1.5f, 0.f, -1.f, -0.f, 0.3714f, -0.9285f, 0.493695f, 0.496114f,
        -0.5f, 0.f, -1.f, -0.f, 0.3714f, -0.9285f, 0.212468f, 0.339446f,
        0.f, 2.5f, 0.f, -0.f, 0.3714f, -0.9285f, 0.493695f, 0.f,

        -1.5f, 0.f, 1.f, -0.f, 0.3714f, 0.9285f, 0.493695f, 0.493695f,
        0.5f, 0.f, 1.f, -0.f, 0.3714f, 0.9285f, 0.650362f, 0.212468f,
        0.f, 2.5f, 0.f, -0.f, 0.3714f, 0.9285f, 0.989809f, 0.493695f,

        0.5f, 0.f, 1.f, 0.8422f, 0.3369f, 0.4211f, 0.650362f, 0.212468f,
        1.5f, 0.f, -1.f, 0.8422f, 0.3369f, 0.4211f, 0.940877f, 0.f,
        0.f, 2.5f, 0.f, 0.8422f, 0.3369f, 0.4211f, 0.989809f, 0.493695f,

        -0.5f, 0.f, -1.f, -0.f, -1.f, -0.f, 0.287935f, 0.856032f,
        1.5f, 0.f, -1.f, -0.f, -1.f, -0.f, -0.f, 1.f,
        0.5f, 0.f, 1.f, -0.f, -1.f, -0.f, 0.f, 0.640081f
    };

    auto mesh = MeshManager::CreateMesh(vbo_data, vbo_data.size()/8, "Mesh #1");
    mesh->AttachShader(d_shader);
    mesh->mesh_position = {0.0f, 0.0f, 0.0f};
    mesh->mesh_rotation = {0.0f, 0.0f, 0.0f};
    mesh->mesh_scale = {5.f, 5.f, 5.f};
    Engine::StartLoop();
    return 0;
}