#ifndef AAB91503_3BAE_4B0F_9DDC_ED14E41F6ED3
#define AAB91503_3BAE_4B0F_9DDC_ED14E41F6ED3

#include "../../Utils/OpenGLInclude.hpp"
#include "../Light.hpp"

#include <iostream>

class PBRLight : public Light
{
public:
    PBRLight(LightType l_type, const glm::vec3& l_pos, const glm::vec3& l_dir, const glm::vec3& l_col, float intensity, float cut_off_, size_t id):
    Light(l_type, l_pos, l_dir, l_col, intensity, cut_off_, id)
    {};
    ~PBRLight(){};

    virtual void Update(float delta_t){};
};

typedef PBRLight PBR_DirectionalLight;
typedef PBRLight PBR_PointLight;
typedef PBRLight PBR_SpotLight;

#endif /* AAB91503_3BAE_4B0F_9DDC_ED14E41F6ED3 */
