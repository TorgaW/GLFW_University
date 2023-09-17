#include "Shaders.hpp"

void Shader::CreateShader(char *vertex_shader_source, char *fragment_shader_source)
{
    unsigned int vshader_id;
    unsigned int fshader_id;

    // create shader id
    vshader_id = glCreateShader(GL_VERTEX_SHADER);
    // attach source
    glShaderSource(vshader_id, 1, &vertex_shader_source, nullptr);
    // compile shader
    glCompileShader(vshader_id);
    int success;
    char infoLog[512];
    // get shader log
    glGetShaderiv(vshader_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vshader_id, 512, nullptr, infoLog);
        std::cout << "SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }
    // repeat for fragment shader...

    fshader_id = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fshader_id, 1, &fragment_shader_source, nullptr);
    glCompileShader(fshader_id);
    glGetShaderiv(vshader_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vshader_id, 512, nullptr, infoLog);
        std::cout << "SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // create shader program
    shader_program_id = glCreateProgram();
    // attach vertex shader
    glAttachShader(shader_program_id, vshader_id);
    // attach fragment shader
    glAttachShader(shader_program_id, fshader_id);
    // link program
    glLinkProgram(shader_program_id);

    // check for errors
    glGetProgramiv(shader_program_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shader_program_id, 512, nullptr, infoLog);
        std::cout << "SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }

    // clean memory from shader objects
    glDeleteShader(vshader_id);
    glDeleteShader(fshader_id);
}

Shader::Shader()
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open("Resources/Shaders/DefaultVertex.vert");
        fShaderFile.open("Resources/Shaders/DefaultFragment.frag");
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    CreateShader(vShaderCode, fShaderCode);
}

Shader::Shader(std::string vertex_path, std::string fragment_path)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertex_path);
        fShaderFile.open(fragment_path);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    CreateShader(vShaderCode, fShaderCode);
}

// Shader::Shader(char *vertex_shader_source, char *fragment_shader_source)
// {
//     CreateShader(vertex_shader_source, fragment_shader_source);
// }

void Shader::Use()
{
    glUseProgram(shader_program_id);
}
