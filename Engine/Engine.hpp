#ifndef D2DE301B_4459_449B_BE5A_2CA870E93E66
#define D2DE301B_4459_449B_BE5A_2CA870E93E66

#include <iostream>

#include "Utils/EngineUtil.hpp"
#include "Utils/Time/TimeUtil.hpp"
#include "Managers/MeshManager/MeshManager.hpp"
#include "Render/Render.hpp"

#define ENGINE_DEFAULT_SCREEN_SIZE_X 1200
#define ENGINE_DEFAULT_SCREEN_SIZE_Y 720

class Engine
{
public:

public:
    //Init functions
    static bool Init();
    static bool Init(uint16_t screen_size_x, uint16_t screen_size_y);

    //While loop function
    static void StartLoop();

    //Terminate Engine
    static inline void Terminate()
    {
        engine_terminate_flag = true;
    };
public:
    Engine(){};
    ~Engine(){};

private:
    static inline bool engine_terminate_flag {false};

private:
    static bool EngineInit(uint16_t screen_size_x, uint16_t screen_size_y);
    static void EngineTerminate();
};


#endif /* D2DE301B_4459_449B_BE5A_2CA870E93E66 */
