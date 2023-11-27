#version 410 core

layout (location = 0) in vec3 l_pos;
layout (location = 1) in vec3 l_normal;
layout (location = 2) in vec2 l_tex_coords;

out vec2 f_tex_uv;
out vec3 f_world_pos;
out vec3 f_normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform mat3 normal_matrix;

void main()
{
    f_tex_uv = l_tex_coords;
    f_world_pos = vec3(model * vec4(l_pos, 1.0));
    f_normal = normal_matrix * l_normal;

    gl_Position =  projection * view * vec4(f_world_pos, 1.0);
}