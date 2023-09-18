#include "Shader.hpp"

uint32_t Shader::LoadShaderFromFile(const std::string &path_to_file, uint32_t gl_shader_type__)
{
    // read file
    std::fstream file_s(path_to_file);
    std::stringstream buff;
    buff << file_s.rdbuf();
    std::string ss_t = buff.str();
    const char *s_t = ss_t.c_str();
    // create shader
    uint32_t s_id = glCreateShader(gl_shader_type__);
    // give source code of shader
    glShaderSource(s_id, 1, &s_t, nullptr);
    // compile shader
    glCompileShader(s_id);

    // prepare for errors checking
    int success;
    char infoLog[512];
    // get shader log
    glGetShaderiv(s_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(s_id, 512, nullptr, infoLog);
        std::cout << "SHADER::COMPILATION_FAILED\n in "
                  << (gl_shader_type__ == GL_VERTEX_SHADER ? " VERTEX\n" : " FRAGMENT\n")
                  << infoLog << std::endl;
        return 0;
    }
    // if success
    return s_id;
}

Shader::Shader(const std::string &fragment_shader_path, size_t id, ShaderType type, const std::string &vertex_shader_path)
{
    uint32_t vs_id, fs_id;
    // load shader files
    vs_id = LoadShaderFromFile(vertex_shader_path, GL_VERTEX_SHADER);
    fs_id = LoadShaderFromFile(fragment_shader_path, GL_FRAGMENT_SHADER);

    // create shader program
    shader_program_id = glCreateProgram();
    glAttachShader(shader_program_id, vs_id);
    glAttachShader(shader_program_id, fs_id);
    // link
    glLinkProgram(shader_program_id);

    // prepare for errors checking
    int success;
    char infoLog[512];
    // check for errors
    glGetProgramiv(shader_program_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shader_program_id, 512, nullptr, infoLog);
        std::cout << "SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }

    // clean memory from shader objects
    glDeleteShader(vs_id);
    glDeleteShader(fs_id);

    //misc
    shader_id = id;
    shader_type = type;
}

GLint Shader::GetUniformLocation(const std::string &name) const
{
    if(shader_uniforms_cache.contains(name))
        return shader_uniforms_cache[name];
    
    GLint location = glGetUniformLocation(shader_program_id, name.c_str());
    shader_uniforms_cache[name] = location;
    return location;
}
