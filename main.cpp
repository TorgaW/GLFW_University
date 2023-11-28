#include "Engine/Engine.hpp"

int main(void)
{
    if(!Engine::Init())
        return 1;

    CameraManager::CreateCameraAndSetAsActive();
    CameraManager::active_camera->camera_position = {-10.0f, 0.0f, 0.0f};
    CameraManager::active_camera->camera_fov = 50.0f;
    // auto sun = LightManager::CreatePhongDirectionalLight({-1.0f, 1.0f, 1.0f}, EngineColors::white, 1.0f);
    auto d_shader = ShaderManager::CreateDefaultPhongShader();

    // std::vector<float> vbo_data = {
    //     -0.5f, 0.f, -1.f, -0.f, -1.f, -0.f, 0.287935f, 0.856032f,
    //     0.5f, 0.f, 1.f, -0.f, -1.f, -0.f, 0.f, 0.640081f,
    //     -1.5f, 0.f, 1.f, -0.f, -1.f, -0.f, 0.287935f, 0.496114f,

    //     -0.5f, 0.f, -1.f, -0.8422f, 0.3369f, -0.4211f, 0.212468f, 0.339446f,
    //     -1.5f, 0.f, 1.f, -0.8422f, 0.3369f, -0.4211f, 0.f, 0.048931f,
    //     0.f, 2.5f, 0.f, -0.8422f, 0.3369f, -0.4211f, 0.493695f, 0.f,

    //     1.5f, 0.f, -1.f, -0.f, 0.3714f, -0.9285f, 0.493695f, 0.496114f,
    //     -0.5f, 0.f, -1.f, -0.f, 0.3714f, -0.9285f, 0.212468f, 0.339446f,
    //     0.f, 2.5f, 0.f, -0.f, 0.3714f, -0.9285f, 0.493695f, 0.f,

    //     -1.5f, 0.f, 1.f, -0.f, 0.3714f, 0.9285f, 0.493695f, 0.493695f,
    //     0.5f, 0.f, 1.f, -0.f, 0.3714f, 0.9285f, 0.650362f, 0.212468f,
    //     0.f, 2.5f, 0.f, -0.f, 0.3714f, 0.9285f, 0.989809f, 0.493695f,

    //     0.5f, 0.f, 1.f, 0.8422f, 0.3369f, 0.4211f, 0.650362f, 0.212468f,
    //     1.5f, 0.f, -1.f, 0.8422f, 0.3369f, 0.4211f, 0.940877f, 0.f,
    //     0.f, 2.5f, 0.f, 0.8422f, 0.3369f, 0.4211f, 0.989809f, 0.493695f,

    //     -0.5f, 0.f, -1.f, -0.f, -1.f, -0.f, 0.287935f, 0.856032f,
    //     1.5f, 0.f, -1.f, -0.f, -1.f, -0.f, -0.f, 1.f,
    //     0.5f, 0.f, 1.f, -0.f, -1.f, -0.f, 0.f, 0.640081f
    // };

    auto directionalLightSource = LightManager::CreatePBRDirectionalLight({0.0f, 0.1f, 0.1f}, EngineColors::white, 1.0f);
    // auto pointLightSource = LightManager::CreatePBRPointLight({5.0f, 10.0f, 0.0f}, EngineColors::red, 10.0f);
    // auto spotLightSource = LightManager::CreatePBRSpotLight({50.0f, 30.0f, 10.0f}, {-50.0f, -30.0f, -10.0f}, EngineColors::green, 2.0f, 1.5f, 25.5f);

    auto mesh = MeshManager::CreateMesh("Resources/Models/octhadon_12a.obj", "Mesh #1");
    mesh->AttachShader(d_shader);
    mesh->material = new PBRMaterial();
    mesh->mesh_position = {0.0f, 0.0f, 0.0f};
    mesh->mesh_rotation = {0.0f, 0.0f, 0.0f};
    mesh->mesh_scale = {5.f, 5.f, 5.f};
    // mesh->mesh_texture = new Texture("Resources/Textures/brick.jpg");
    mesh->material->Load();
    mesh->material->t_albedo_intensity = 1.5f;
    mesh->material->t_metallic_map_intensity = 0.6f;
    mesh->material->t_roughness_map_intensity = 0.4f;
    mesh->material->SetTextures(new Texture("Resources/Textures/PBR/damba_albedo.png"), new Texture("Resources/Textures/PBR/damba_normal.png"),
                                new Texture("Resources/Textures/PBR/damba_metallic.png"), new Texture("Resources/Textures/PBR/damba_roughness.png"),
                                new Texture("Resources/Textures/PBR/damba_ao.png"));

    // auto mesh2 = MeshManager::CreateMesh(vbo_data, vbo_data.size()/8, "Mesh #2");
    // mesh2->AttachShader(d_shader);
    // mesh2->mesh_position = {10.0f, 5.0f, 10.0f};
    // mesh2->mesh_rotation = {0.0f, 0.0f, 0.0f};
    // mesh2->mesh_scale = {5.f, 5.f, 5.f};
    // mesh2->mesh_texture = new Texture("Resources/Textures/brick.jpg");


    Engine::StartLoop();
    return 0;
}