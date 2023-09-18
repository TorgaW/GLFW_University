#include "ShaderManager.hpp"

Shader *ShaderManager::CreateDefaultUnlitShader()
{
    Shader *t = new Shader("Resources/Shaders/DefaultFragment.frag", (last_shader_id++), ShaderType::Unlit);
    shaders_pool.push_back(t);
    return t;
}

Shader *ShaderManager::CreateDefaultPhongShader()
{
    Shader *t = new Shader("Resources/Shaders/PhongModel/DefaultPhongFragment.frag", (last_shader_id++),
                           ShaderType::Phong, "Resources/Shaders/PhongModel/DefaultPhongVertex.vert");
    shaders_pool.push_back(t);
    return t;
}

Shader *ShaderManager::CreateShaderFromFiles(const std::string &frag_path, ShaderType type, const std::string &vert_path)
{
    Shader *t = new Shader(frag_path, (last_shader_id++), type, vert_path);
    shaders_pool.push_back(t);
    return t;
}
