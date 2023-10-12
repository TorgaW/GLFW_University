#version 410 core
#define MAX_LIGHTS 16
struct LightSource
{
    int type;
    vec3 position;
    vec3 direction;
    vec3 color;
    float intensity;
};

in vec3 f_position;
in vec3 f_normal;
in vec2 f_uv;

uniform LightSource lights[MAX_LIGHTS];
uniform int lights_number;

out vec4 fragColor;

void main()
{
    float ambient = 0.1;
    vec3 ambient_strength = vec3(1.0);
    vec3 normal = normalize(f_normal);
    float diff = 0.0;
    vec3 diffuse = vec3(1.0);
    for(int i = 0; i < lights_number; i++) {
        ambient_strength *= lights[i].color * lights[i].intensity;
        diff = max(dot(normal, normalize(lights[i].direction)), 0.0);
        diffuse *= (diff * lights[i].color);
    }
    fragColor = vec4((ambient + diffuse), 1.0) * vec4(f_uv.xy, 0.0, 1.0);
}