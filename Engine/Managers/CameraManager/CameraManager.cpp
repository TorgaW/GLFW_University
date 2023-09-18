#include "CameraManager.hpp"

Camera *CameraManager::CreateCamera()
{
    Camera *t = new Camera(last_camera_id++);
    cameras_pool.push_back(t);
    return t;
}

Camera *CameraManager::CreateCameraAndSetAsActive()
{
    Camera *t = new Camera(last_camera_id++);
    cameras_pool.push_back(t);
    active_camera = t;
    return t;
}

void CameraManager::SetActiveCamera(Camera *new_camera)
{
    if(new_camera == nullptr) return;
    active_camera = new_camera;
}
