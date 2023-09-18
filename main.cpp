#include "Engine/Engine.hpp"

int main(void)
{
    if(!Engine::Init())
        return 1;

    CameraManager::CreateCameraAndSetAsActive();
    auto mesh = MeshManager::CreateMesh("Resources/Models/rocket_01.obj", "Mesh #1");
    auto d_shader = ShaderManager::CreateDefaultShader();
    mesh->AttachShader(d_shader);
    Engine::StartLoop();
    return 0;
}