#ifndef D6E45A46_2BFF_46D1_AAE3_092473A28BC2
#define D6E45A46_2BFF_46D1_AAE3_092473A28BC2

#include "../Utils/OpenGLInclude.hpp"
#include <vector>
#include <string>
#include "../Managers/ShaderManager/ShaderManager.hpp"
#include "../Texture/Texture.hpp"

class PBRMaterial
{
public:
    Shader *mat_shader {nullptr};

    /**
        uniform sampler2D t_albedo;
        uniform sampler2D t_normal_map;
        uniform sampler2D t_metallic_map;
        uniform sampler2D t_roughness_map;
        uniform sampler2D t_ao_map;
    */
    Texture *t_albedo {nullptr};
    Texture *t_normal_map {nullptr};
    Texture *t_metallic_map {nullptr};
    Texture *t_roughness_map {nullptr};
    Texture *t_ao_map {nullptr};
    Texture *t_albedo_2 {nullptr};
    Texture *t_normal_map_2 {nullptr};
    Texture *t_metallic_map_2 {nullptr};
    Texture *t_roughness_map_2 {nullptr};
    Texture *t_ao_map_2 {nullptr};
    float t_albedo_intensity {1.0f};
    float t_normal_map_intensity {1.0f};
    float t_metallic_map_intensity {1.0f};
    float t_roughness_map_intensity {1.0f};
    float t_ao_map_intensity {1.0f};

    void Load();
    void LoadFrom(const std::string& vert, const std::string& frag);

    void SetTextures(Texture *t_albedo_, Texture *t_normal_map_, Texture *t_metallic_map_, Texture *t_roughness_map_, Texture *t_ao_map_);
    void SetTextures2(Texture *t_albedo_, Texture *t_normal_map_, Texture *t_metallic_map_, Texture *t_roughness_map_, Texture *t_ao_map_);

    void SetShaderTexturesDuringRender();
};


#endif /* D6E45A46_2BFF_46D1_AAE3_092473A28BC2 */
