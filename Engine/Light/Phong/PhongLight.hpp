#ifndef A1D037E0_1FDE_4D82_B75D_046A1825A925
#define A1D037E0_1FDE_4D82_B75D_046A1825A925

#include "../../Utils/OpenGLInclude.hpp"
#include "../Light.hpp"

#include <iostream>

class PhongLight : public Light
{
public:
    float t_param{0.0f};
public:
    PhongLight(LightType l_type, const glm::vec3& l_pos, const glm::vec3& l_dir, const glm::vec3& l_col, float intensity, float cut_off_, size_t id):
    Light(l_type, l_pos, l_dir, l_col, intensity, cut_off_, id)
    {};
    ~PhongLight(){};

    virtual void Update(float delta_t)
    {
        // (-2.59, 8.28, 0.87) + (11.26 cos(t) + 2.41 sin(t), 9.97 cos(t) - 3.48 sin(t), -1.29 cos(t) - 5.88 sin(t))
        // kirill : (2.31, -8.76, 13.55) + (2.18 cos(t) - 3.9 sin(t), -7.91 cos(t) + 1.02 sin(t), -5.73 cos(t) - 2.88 sin(t))
        // t_param += delta_t * 1.0f;
        // std::cout << t_param << "\n";
        // if(t_param > 2.0f * 3.1416f) t_param = 0.0f; 
        // glm::vec3 p(-2.59f, 8.28f, 0.87f);
        // float t_x = 11.26f * std::cos(t_param) + 2.41f * std::sin(t_param);
        // float t_y = 9.97 * std::cos(t_param) - 3.48f * std::sin(t_param);
        // float t_z = -1.29f * std::cos(t_param) - 5.88f * std::sin(t_param);
        // light_direction = -(glm::vec3(t_x, t_y, t_z) + p);
        // std::cout << light_direction.x << " " << light_direction.y << " " << light_direction.z << "\n";
        // light_direction = glm::lookAt(light_position, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f});
        
    };
};

typedef PhongLight P_DirectionalLight;
typedef PhongLight P_PointLight;
typedef PhongLight P_SpotLight;
typedef PhongLight P_SkyLight;

#endif /* A1D037E0_1FDE_4D82_B75D_046A1825A925 */
