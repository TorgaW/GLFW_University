#ifndef B341E8DB_8589_46D7_A758_F57A415F0F3C
#define B341E8DB_8589_46D7_A758_F57A415F0F3C

#include <GLFW/glfw3.h>

class TimeUtils
{
private:
    static inline double prevFrameTime {0.0};
    static inline double currentFrameTime {0.0};
    static inline double deltaTime {0.0};
    static inline double timePassed {0.0};
public:
    static double UpdateDeltaTime();

    static inline double GetDeltaTime() { return deltaTime; };
    static inline double GetTimeSinceStart() { return timePassed; };

    TimeUtils(){};
    ~TimeUtils(){};
};


#endif /* B341E8DB_8589_46D7_A758_F57A415F0F3C */
