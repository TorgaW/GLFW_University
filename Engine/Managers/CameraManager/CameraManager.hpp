#ifndef CA1D1AD0_6A48_42EC_93E6_2673F6D054A7
#define CA1D1AD0_6A48_42EC_93E6_2673F6D054A7

#include "../../Camera/Camera.hpp"
#include <vector>

class CameraManager
{
private:
    static inline std::vector<Camera*> cameras_pool {};
    static inline size_t last_camera_id {0};
public:
    static inline Camera *active_camera {nullptr};
public:
    /**
     * @brief Create a Camera object
     * 
     */
    static Camera *CreateCamera();

    /**
     * @brief Create a Camera object and set as active camera
     * 
     */
    static Camera *CreateCameraAndSetAsActive();

    /**
     * @brief Set new active Camera object
     * 
     * @param new_camera ptr to camera
     */
    static void SetActiveCamera(Camera *new_camera);
public:
    CameraManager(){};
    ~CameraManager(){};
};


#endif /* CA1D1AD0_6A48_42EC_93E6_2673F6D054A7 */
