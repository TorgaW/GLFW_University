#ifndef EA700BD5_B32E_4BE6_8C93_A0EA3B3C49D0
#define EA700BD5_B32E_4BE6_8C93_A0EA3B3C49D0

enum LightType
{
    Directional = 0,
    Point = 1,
    Spot = 2,
    Sky = 3
};

class Light
{
public:
    LightType light_type;
    glm::vec3 light_position;
    glm::vec3 light_direction;
    glm::vec3 light_color;
    float light_intensity;
    size_t light_id;

public:
    Light(LightType l_type, const glm::vec3& l_pos, const glm::vec3& l_dir, const glm::vec3& l_col, float intensity, size_t id):
    light_type(l_type), light_position(l_pos), light_direction(l_dir), light_color(l_col), light_intensity(intensity), light_id(id)
    {};
    virtual ~Light(){};

    /**
     * @brief Update light state every tick
     * 
     */
    virtual void Update(){};
};


#endif /* EA700BD5_B32E_4BE6_8C93_A0EA3B3C49D0 */
