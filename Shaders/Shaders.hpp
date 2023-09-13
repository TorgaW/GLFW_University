#ifndef BDE74069_7BF9_4270_BDB0_0C03DA3E6CCF
#define BDE74069_7BF9_4270_BDB0_0C03DA3E6CCF

#include "../glad.h"
#include "../glm/glm.hpp"
#include <iostream>

//basic shaders
inline const char *fragmentShaderSource {
    "#version 410 core\n"
    "out vec4 fragColor;\n"
    "void main()\n"
    "{\n"
    "   fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0"};
inline const char *vertexShaderSource {
    "#version 410 core\n"
    "layout (location = 0) in vec3 position;\n"
    "uniform mat4 transform;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = projection * view * model * vec4(position, 1.0f);\n"
    "}\0"};

class Shader
{
private:
    unsigned int shader_program_id;
private:
    void CreateShader(char *vertex_shader_source, char *fragment_shader_source);
public:

    void setBool(const std::string &name, bool value) const
    {         
        glUniform1i(glGetUniformLocation(shader_program_id, name.c_str()), (int)value); 
    }
    // ------------------------------------------------------------------------
    void setInt(const std::string &name, int value) const
    { 
        glUniform1i(glGetUniformLocation(shader_program_id, name.c_str()), value); 
    }
    // ------------------------------------------------------------------------
    void setFloat(const std::string &name, float value) const
    { 
        glUniform1f(glGetUniformLocation(shader_program_id, name.c_str()), value); 
    }
    // ------------------------------------------------------------------------
    void setVec2(const std::string &name, const glm::vec2 &value) const
    { 
        glUniform2fv(glGetUniformLocation(shader_program_id, name.c_str()), 1, &value[0]); 
    }
    void setVec2(const std::string &name, float x, float y) const
    { 
        glUniform2f(glGetUniformLocation(shader_program_id, name.c_str()), x, y); 
    }
    // ------------------------------------------------------------------------
    void setVec3(const std::string &name, const glm::vec3 &value) const
    { 
        glUniform3fv(glGetUniformLocation(shader_program_id, name.c_str()), 1, &value[0]); 
    }
    void setVec3(const std::string &name, float x, float y, float z) const
    { 
        glUniform3f(glGetUniformLocation(shader_program_id, name.c_str()), x, y, z); 
    }
    // ------------------------------------------------------------------------
    void setVec4(const std::string &name, const glm::vec4 &value) const
    { 
        glUniform4fv(glGetUniformLocation(shader_program_id, name.c_str()), 1, &value[0]); 
    }
    void setVec4(const std::string &name, float x, float y, float z, float w) const
    { 
        glUniform4f(glGetUniformLocation(shader_program_id, name.c_str()), x, y, z, w); 
    }
    // ------------------------------------------------------------------------
    void setMat2(const std::string &name, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(shader_program_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat3(const std::string &name, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(shader_program_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(shader_program_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

public:
    Shader();
    Shader(char *vertex_shader_source, char *fragment_shader_source);
    void Use();
    inline unsigned int GetShaderID() { return shader_program_id; };
    ~Shader(){};
};


#endif /* BDE74069_7BF9_4270_BDB0_0C03DA3E6CCF */
