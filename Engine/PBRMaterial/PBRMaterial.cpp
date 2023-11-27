#include "PBRMaterial.hpp"

void PBRMaterial::Load()
{
    mat_shader = ShaderManager::CreateDefaultPBRShader();
}

void PBRMaterial::LoadFrom(const std::string &vert, const std::string &frag)
{
    mat_shader = ShaderManager::CreateShaderFromFiles(frag, ShaderType::PBR, vert);
}

void PBRMaterial::SetTextures(Texture *t_albedo_, Texture *t_normal_map_, Texture *t_metallic_map_, Texture *t_roughness_map_, Texture *t_ao_map_)
{
    t_albedo = t_albedo_;
    t_normal_map = t_normal_map_;
    t_metallic_map = t_metallic_map_;
    t_roughness_map = t_roughness_map_;
    t_ao_map = t_ao_map_;
}

void PBRMaterial::SetShaderTexturesDuringRender()
{
    if(mat_shader != nullptr)
    {
        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D, t_albedo->gl_bitmap_index);
        glActiveTexture(GL_TEXTURE3);
        glBindTexture(GL_TEXTURE_2D, t_normal_map->gl_bitmap_index);
        glActiveTexture(GL_TEXTURE4);
        glBindTexture(GL_TEXTURE_2D, t_metallic_map->gl_bitmap_index);
        glActiveTexture(GL_TEXTURE5);
        glBindTexture(GL_TEXTURE_2D, t_roughness_map->gl_bitmap_index);
        glActiveTexture(GL_TEXTURE6);
        glBindTexture(GL_TEXTURE_2D, t_ao_map->gl_bitmap_index);
    }
}