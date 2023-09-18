#version 410 core
in vec3 f_position;
in vec3 f_normal;
in vec2 f_uv;

out vec4 fragColor;

void main()
{
    fragColor = vec4(vec2(f_uv.x, f_uv.y), 0.0, 1.0);
}