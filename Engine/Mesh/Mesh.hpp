#ifndef D27635D6_6A2D_4B19_96D3_4F1B8605418A
#define D27635D6_6A2D_4B19_96D3_4F1B8605418A

#include "../Utils/OpenGLInclude.hpp"
#include <vector>
#include <string>
#include "../Shader/Shader.hpp"
#include "../Texture/Texture.hpp"

class Mesh
{
public:
    std::string mesh_name;
    size_t mesh_id;
private:
    uint32_t mesh_VBO; //vertex buffer
    uint32_t mesh_VAO; //vertex attributes
    size_t mesh_indices {0};
    Shader *mesh_shader {nullptr}; //shader for the mesh
public:
    glm::vec3 mesh_position {0.0f};
    glm::vec3 mesh_rotation {0.0f};
    glm::vec3 mesh_scale {1.0f};
public:
    bool b_enable_tick_update {false};

    Texture *mesh_texture {nullptr};

public:
    //Attach shader to the mesh shader pipeline
    inline void AttachShader(Shader* shader_program)
    {
        mesh_shader = shader_program;
    };

    //get mesh shader
    inline Shader *GetMeshShader() { return mesh_shader; };

public:

    inline uint32_t GetVAO() { return mesh_VAO; };

    inline size_t GetIndices() { return mesh_indices; };

public:
    //Creates Mesh with name and id from VBO data.
    //
    //VBO data must be presented as described below:
    //
    //////////////////////////////////////////////////////
    //||vertex coordinates | vertex normals | vertex uvs||
    //////////////////////////////////////////////////////
    Mesh(const std::string& name, size_t id, const std::vector<float>& vbo_data, size_t indices_n);
    ~Mesh(){};
};


#endif /* D27635D6_6A2D_4B19_96D3_4F1B8605418A */
