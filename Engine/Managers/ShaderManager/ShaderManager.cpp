#include "ShaderManager.hpp"

Shader *ShaderManager::CreateDefaultShader()
{
    Shader *t = new Shader("Resources/Shaders/DefaultFragment.frag", (last_shader_id++));
    shaders_pool.push_back(t);
    return t;
}

Shader *ShaderManager::CreateShaderFromFiles(const std::string &frag_path, const std::string &vert_path)
{
    Shader *t = new Shader(frag_path, (last_shader_id++), vert_path);
    shaders_pool.push_back(t);
    return t;
}
