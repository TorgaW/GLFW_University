#ifndef ED1CF5AC_0473_44B9_8A55_551EF30C6F18
#define ED1CF5AC_0473_44B9_8A55_551EF30C6F18

#include "../Utils/OpenGLInclude.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>

class Shader
{
private:
    uint32_t shader_program_id;
    mutable std::unordered_map<std::string, u_int32_t> shader_uniforms_cache;
public:
    size_t shader_id {0};
private:
    /**
     * @brief Load and compile shader from file
     *
     * @param path_to_file path to file
     * @param gl_shader_type__ type of GL Shader (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER)
     * @returns Shader's id
     */
    uint32_t LoadShaderFromFile(const std::string &path_to_file, uint32_t gl_shader_type__);

public:
    /**
     * @brief Construct a new Shader object from shader files
     *
     * @param fragment_shader_path path to fragment shader
     * @param vertex_shader_path path to vertex shader (if not provided will be used default vertex shader)
     */
    Shader(const std::string &fragment_shader_path, size_t id, const std::string &vertex_shader_path = "Resources/Shaders/DefaultVertex.vert");
    ~Shader(){};

public:

    inline void UseShader()
    {
        glUseProgram(shader_program_id);
    };

public:
    //-----------------------Shader setters--------------------------//
    void setBool(const std::string &name, bool value) const
    {   
        glUniform1i(GetUniformLocation(name), (int)value);
    }
    // ------------------------------------------------------------------------
    void setInt(const std::string &name, int value) const
    {
        glUniform1i(GetUniformLocation(name), value);
    }
    // ------------------------------------------------------------------------
    void setFloat(const std::string &name, float value) const
    {
        glUniform1f(GetUniformLocation(name), value);
    }
    // ------------------------------------------------------------------------
    void setVec2(const std::string &name, const glm::vec2 &value) const
    {
        glUniform2fv(GetUniformLocation(name), 1, &value[0]);
    }
    void setVec2(const std::string &name, float x, float y) const
    {
        glUniform2f(GetUniformLocation(name), x, y);
    }
    // ------------------------------------------------------------------------
    void setVec3(const std::string &name, const glm::vec3 &value) const
    {
        glUniform3fv(GetUniformLocation(name), 1, &value[0]);
    }
    void setVec3(const std::string &name, float x, float y, float z) const
    {
        glUniform3f(GetUniformLocation(name), x, y, z);
    }
    // ------------------------------------------------------------------------
    void setVec4(const std::string &name, const glm::vec4 &value) const
    {
        glUniform4fv(GetUniformLocation(name), 1, &value[0]);
    }
    void setVec4(const std::string &name, float x, float y, float z, float w) const
    {
        glUniform4f(GetUniformLocation(name), x, y, z, w);
    }
    // ------------------------------------------------------------------------
    void setMat2(const std::string &name, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat3(const std::string &name, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
    }

private:
    GLint GetUniformLocation(const std::string &name) const;
};

#endif /* ED1CF5AC_0473_44B9_8A55_551EF30C6F18 */
