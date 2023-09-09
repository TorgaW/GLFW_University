#ifndef B6F3ADB2_2E76_4FDB_9CC1_A6E3B4CF5F46
#define B6F3ADB2_2E76_4FDB_9CC1_A6E3B4CF5F46

#include "../glm/glm.hpp"
#include "../glad.h"
#include <cstddef>
#include <string>
#include <cstring>

class Object
{
private:
    unsigned int object_VBO; //vertex buffer
    unsigned int object_VAO; //vertex attributes
    unsigned int object_EBO; //optional elements buffer

    float *object_vertices; //object vertices
    unsigned int *object_indices; //optional indices for elements buffer

    std::string object_name;
    size_t object_id;

    glm::vec3 object_absolute_position {0.0f};
    glm::vec3 object_relative_position {0.0f};
    glm::vec3 object_scale {1.0f};

public:
    Object(float *vertices, size_t vert_num, std::string name, size_t id);
    virtual ~Object(){};

public:
    //called before first render
    virtual void Begin(){};

    //called every frame before 'Draw()' function
    virtual void Update(float delta_time){};

    //called every frame
    virtual void Draw(float delta_time)
    {
        glBindVertexArray(object_VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    };

    //called before destruction
    virtual void End(){};

public:

    inline std::string GetName()
    {
        return object_name;
    };

};


#endif /* B6F3ADB2_2E76_4FDB_9CC1_A6E3B4CF5F46 */
