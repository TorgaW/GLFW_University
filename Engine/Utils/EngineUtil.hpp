#ifndef B7A0183A_4DEA_4440_B058_2D0243D5FCC2
#define B7A0183A_4DEA_4440_B058_2D0243D5FCC2

#include "OpenGLInclude.hpp"

class EngineColors
{
public:
    static inline glm::vec3 white {1.0f};
    static inline glm::vec3 black {0.0f};
    static inline glm::vec3 red {1.0f, 0.0f, 0.0f};
    static inline glm::vec3 green {0.0f, 1.0f, 0.0f};
    static inline glm::vec3 blue {0.0f, 0.0f, 1.0f};
    static inline glm::vec3 yellow {1.0f, 1.0f, 0.0f};
    static inline glm::vec3 cyan {0.0f, 1.0f, 1.0f};
    static inline glm::vec3 magenta {1.0f, 0.0f, 1.0f};
public:
    EngineColors(){};
    ~EngineColors(){};
};

class EngineUtil
{
public:
    static inline GLFWwindow *glfw_window{nullptr};
    static inline uint32_t window_width{0};
    static inline uint32_t window_height{0};
    static inline float window_width_f{0};
    static inline float window_height_f{0};

public:
    EngineUtil(){};
    ~EngineUtil(){};
};

#endif /* B7A0183A_4DEA_4440_B058_2D0243D5FCC2 */
