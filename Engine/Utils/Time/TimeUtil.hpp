#ifndef D5F4EFC8_28B9_435E_8D11_31402B886D88
#define D5F4EFC8_28B9_435E_8D11_31402B886D88

#include <GLFW/glfw3.h>

class TimeUtil
{
public:
    /**
     * @brief Update delta time and time since start (in seconds)
     * 
     */
    static inline void UpdateTime()
    {
        current_frame_time = glfwGetTime();
        delta_time = current_frame_time = prev_frame_time;
        time_since_start = current_frame_time;
        prev_frame_time = current_frame_time;
    };

public:
    static inline double GetDeltaTime() { return delta_time; };
    static inline double GetTimeSinceStart() { return time_since_start; };

private:
    static inline double prev_frame_time{0.0f};
    static inline double current_frame_time{0.0f};
    static inline double delta_time{0.0f};
    static inline double time_since_start{0.0f};

public:
    TimeUtil(){};
    ~TimeUtil(){};
};

#endif /* D5F4EFC8_28B9_435E_8D11_31402B886D88 */
