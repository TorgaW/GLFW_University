#ifndef BD4D07DF_84BD_418F_B1D4_C07DF62151DA
#define BD4D07DF_84BD_418F_B1D4_C07DF62151DA

#include "../glm/glm.hpp"

class Transformations
{
private:
    inline static glm::mat4 current_transform {};
    inline static glm::vec3 current_scale {};
public:

    //2D
    static void Translate(glm::vec3 translate_vector);
    static void Rotate(float angle, glm::vec3 axis);
    static void Scale(glm::vec3 scale_factor);

    static inline glm::mat4 GetCurrentTransform() { return current_transform; };


    Transformations(){};
    ~Transformations(){};
};


#endif /* BD4D07DF_84BD_418F_B1D4_C07DF62151DA */
