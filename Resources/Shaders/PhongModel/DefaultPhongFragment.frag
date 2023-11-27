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
uniform vec3 viewPosition;

uniform sampler2D tex_0;

out vec4 fragColor;


void main()
{
    float ambient = 0.1;
    vec3 ambient_strength = vec3(1.0);
    vec3 normal = normalize(f_normal);
    float diff = 0.0;
    vec3 diffuse = vec3(1.0);
    vec3 viewDir = vec3(0.0);
    vec3 reflectDir = vec3(0.0);
    float specularStrength = 256;
    viewDir = normalize(viewPosition - f_position);
    vec3 specular = vec3(specularStrength);  
    for(int i = 0; i < lights_number; i++) {
        ambient_strength *= lights[i].color * lights[i].intensity;
        diff = max(dot(normal, normalize(lights[i].direction)), 0.0);
        diffuse *= (diff * lights[i].color);
        reflectDir = reflect(-lights[i].direction, normal);  
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
        specular *= spec * lights[i].color;
    }
    fragColor = vec4((ambient + diffuse), 1.0) * vec4(texture2D(tex_0, f_uv.xy).rgb, 1.0);
}