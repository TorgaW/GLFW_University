#ifndef B9779E7D_BEB1_4755_8C2A_E0338F8B1BA0
#define B9779E7D_BEB1_4755_8C2A_E0338F8B1BA0

#include "../Utils/Mouse/MouseUtils.hpp"

class Camera
{
public:
    size_t camera_id {0};
private:
    glm::mat4 camera_view;
    glm::mat4 camera_projection;
    glm::vec3 camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
public:
    float camera_near_plane {0.1f};
    float camera_far_plane {500.0f};
    float camera_fov {70.0f};
    float camera_speed {0.05f};
    glm::vec3 camera_position {0.0f};
public:
    inline void GetCameraViewAndProjection(glm::mat4 *out_view, glm::mat4 *out_projection)
    {
        *out_view = camera_view;
        *out_projection = camera_projection;
    };
public:
    void UpdateViewAndProjection(float delta_time);
    void UpdateInput(float delta_time);
public:
    Camera(size_t id):camera_id(id){};
    ~Camera(){};
};


#endif /* B9779E7D_BEB1_4755_8C2A_E0338F8B1BA0 */
