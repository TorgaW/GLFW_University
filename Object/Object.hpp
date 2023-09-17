#ifndef B6F3ADB2_2E76_4FDB_9CC1_A6E3B4CF5F46
#define B6F3ADB2_2E76_4FDB_9CC1_A6E3B4CF5F46

#include "../glm/glm.hpp"
#include "../glad.h"
#include <vector>
#include <cstddef>
#include <string>
#include <cstring>

#include "../Shaders/Shaders.hpp"

class Object
{
protected:
    unsigned int object_VBO; //vertex buffer
    unsigned int object_VAO; //vertex attributes
    unsigned int object_EBO; //optional elements buffer

    float *object_vertices; //object vertices
    std::vector<float> object_vert_vector;
    size_t object_vert_num {0};
    size_t object_indicies_num {0};
    size_t object_triangles {0};
    unsigned int *object_indices; //optional indices for elements buffer

    std::string object_name;
    size_t object_id;

    glm::vec3 object_absolute_position {0.0f};
    glm::vec3 object_relative_position {0.0f};
    glm::vec3 object_scale {1.0f};
    glm::vec3 object_rotation_angels {0.0f};

    Shader *object_shader_ptr {nullptr};

public:
    //load object from file path
    Object(std::string file_path, std::string name, size_t id);
    //load object manually
    Object(float *vertices, size_t vert_num, std::string name, size_t id);
    //constructor for pre-defined objects
    Object(std::string name, size_t id){};
    virtual ~Object(){};

public:
    //called before first render
    virtual void Begin(){};

    //called every frame before 'Draw()' function
    virtual void Update(float delta_time){};

    //called every frame
    virtual void Draw(float delta_time){};

    //called before destruction
    virtual void End(){};

public:

    inline std::string GetName()
    {
        return object_name;
    };

    inline void SetShader(Shader *ptr) { object_shader_ptr = ptr; };

};


#endif /* B6F3ADB2_2E76_4FDB_9CC1_A6E3B4CF5F46 */
