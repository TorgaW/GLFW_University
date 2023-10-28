#ifndef A1D037E0_1FDE_4D82_B75D_046A1825A925
#define A1D037E0_1FDE_4D82_B75D_046A1825A925

#include "../../Utils/OpenGLInclude.hpp"
#include "../Light.hpp"

class PhongLight : public Light
{
public:
    PhongLight(LightType l_type, const glm::vec3& l_pos, const glm::vec3& l_dir, const glm::vec3& l_col, float intensity, size_t id):
    Light(l_type, l_pos, l_dir, l_col, intensity, id)
    {};
    ~PhongLight(){};
};

typedef PhongLight P_DirectionalLight;
typedef PhongLight P_PointLight;
typedef PhongLight P_SpotLight;
typedef PhongLight P_SkyLight;

#endif /* A1D037E0_1FDE_4D82_B75D_046A1825A925 */
