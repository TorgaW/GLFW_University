#ifndef FE3F9CC4_B26A_4272_812B_BA12E9147127
#define FE3F9CC4_B26A_4272_812B_BA12E9147127

#include "../Managers/CameraManager/CameraManager.hpp"
#include "../Managers/MeshManager/MeshManager.hpp"
#include "../Managers/ShaderManager/ShaderManager.hpp"
#include "../Managers/LightManager/LightManager.hpp"

class Render
{
public:

    /**
     * @brief Main render pipeline
     * 
     * @param delta_time time between frames
     */
    static void DrawScreen(float delta_time);

public:
    Render(){};
    ~Render(){};
};


#endif /* FE3F9CC4_B26A_4272_812B_BA12E9147127 */
