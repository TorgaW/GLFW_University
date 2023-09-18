#ifndef A1D037E0_1FDE_4D82_B75D_046A1825A925
#define A1D037E0_1FDE_4D82_B75D_046A1825A925

#include "../../Utils/OpenGLInclude.hpp"
#include "../Light.hpp"

class PhongLight
{
public:
    PhongLightType light_type;
    glm::vec3 light_position;
    glm::vec3 light_direction;
    glm::vec3 light_color;
    float light_intensity;
    size_t light_id;
public:
    PhongLight(PhongLightType l_type, const glm::vec3& l_pos, const glm::vec3& l_dir, const glm::vec3& l_col, float intensity, size_t id):
    light_type(l_type), light_position(l_pos), light_direction(l_dir), light_color(l_col), light_intensity(intensity), light_id(id)
    {};
    ~PhongLight(){};
};

typedef PhongLight DirectionalLight;
typedef PhongLight PointLight;
typedef PhongLight SpotLight;
typedef PhongLight SkyLight;

#endif /* A1D037E0_1FDE_4D82_B75D_046A1825A925 */
