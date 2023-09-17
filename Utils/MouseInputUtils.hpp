#ifndef D084D15A_BE7A_497D_98E1_2683FD66732C
#define D084D15A_BE7A_497D_98E1_2683FD66732C

#include <GLFW/glfw3.h>
#include "WindowUtils.hpp"

class MouseInputUtils
{
public:
    static inline double mouse_x_pos{0.0f};
    static inline double mouse_y_pos{0.0f};
    static inline float mouse_yaw {0.0f};
    static inline float mouse_pitch {0.0f};
    static inline float mouse_sensitivity {0.25f};

public:
    MouseInputUtils(){};
    ~MouseInputUtils(){};

    static inline void UpdateMouseInput()
    {
        glfwGetCursorPos(WindowUtils::main_window, &mouse_x_pos, &mouse_y_pos);
        if (first_mouse)
        {
            last_x = mouse_x_pos;
            last_y = mouse_y_pos;
            first_mouse = false;
        }
        float xoffset = mouse_x_pos - last_x;
        float yoffset = last_y - mouse_y_pos;
        last_x = mouse_x_pos;
        last_y = mouse_y_pos;

        xoffset *= mouse_sensitivity;
        yoffset *= mouse_sensitivity;

        mouse_yaw += xoffset;
        mouse_pitch += yoffset;

        if (mouse_pitch > 89.0f)
            mouse_pitch = 89.0f;
        if (mouse_pitch < -89.0f)
            mouse_pitch = -89.0f;
    };

private:
    static inline float last_x = 0.0f, last_y = 0.0f;
    static inline bool first_mouse{true};
};

#endif /* D084D15A_BE7A_497D_98E1_2683FD66732C */
