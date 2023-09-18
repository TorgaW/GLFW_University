#ifndef A2683817_E2A4_490E_83DF_055809624E94
#define A2683817_E2A4_490E_83DF_055809624E94

#include "../../Shader/Shader.hpp"

class ShaderManager
{
private:
    static inline std::vector<Shader*> shaders_pool {};
    static inline size_t last_shader_id {0};
public:
    /**
     * @brief Create a Default Shader object
     * 
     * @return Shader* or nullptr
     */
    static Shader *CreateDefaultShader();

    /**
     * @brief Create a Shader from files
     * 
     * @param frag_path path to fragment shader
     * @param vert_path path to vertex shader
     * @return Shader* or nullptr
     */
    static Shader *CreateShaderFromFiles(const std::string& frag_path, const std::string& vert_path = "Resources/Shaders/DefaultVertex.vert");
public:
    ShaderManager(){};
    ~ShaderManager(){};
};


#endif /* A2683817_E2A4_490E_83DF_055809624E94 */
