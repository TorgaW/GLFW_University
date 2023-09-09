#ifndef BDE74069_7BF9_4270_BDB0_0C03DA3E6CCF
#define BDE74069_7BF9_4270_BDB0_0C03DA3E6CCF

#include "../glad.h"
#include <iostream>

//basic shaders
inline const char *fragmentShaderSource {
    "#version 410 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0"};
inline const char *vertexShaderSource {
    "#version 410 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0"};

class Shader
{
private:
    unsigned int vshader_id;
    unsigned int fshader_id;
    unsigned int shader_program_id;
private:
    void CreateShader(char *vertex_shader_source, char *fragment_shader_source);
public:
    Shader();
    Shader(char *vertex_shader_source, char *fragment_shader_source);
    void Use();
    ~Shader(){};
};


#endif /* BDE74069_7BF9_4270_BDB0_0C03DA3E6CCF */
