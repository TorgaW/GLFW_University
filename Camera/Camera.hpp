#ifndef E3585340_FF27_4DEF_A252_FAE31EE52F66
#define E3585340_FF27_4DEF_A252_FAE31EE52F66

#include <GLFW/glfw3.h>
#include "../glm/glm.hpp"
#include "../Utils/ScreenUtils.hpp"
#include "../Utils/WindowUtils.hpp"

class Camera
{
private:
    glm::mat4 view;
    glm::mat4 projection;
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
public:
    float camera_near_plane {0.1f};
    float camera_far_plane {100.0f};
    glm::vec3 camera_position {0.0f};

public:
    void UpdateView();
    void ProcessInput();

    inline glm::mat4 GetViewMat4() { return view; };
    inline glm::mat4 GetProjectionMat4() { return projection; };

    Camera(){};
    ~Camera(){};
};


#endif /* E3585340_FF27_4DEF_A252_FAE31EE52F66 */
