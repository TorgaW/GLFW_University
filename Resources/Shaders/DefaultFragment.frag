#version 410 core
in vec3 f_position;
in vec3 f_normal;
in vec2 f_uv;

out vec4 fragColor;

void main()
{
    fragColor = vec4(0.7373, 1.0, 0.4941, 1.0);
}