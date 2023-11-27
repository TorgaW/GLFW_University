#version 410 core

struct DirectionalLight
{
    vec3 position;
    vec3 direction;
    vec3 color;
    float intensity;
};

out vec4 frag_color;
in vec2 f_tex_uv;
in vec3 f_world_pos;
in vec3 f_normal;

// material parameters
uniform sampler2D t_albedo;
uniform float p_albedo_intensity;
uniform sampler2D t_normal_map;
uniform float p_normal_map_intensity;
uniform sampler2D t_metallic_map;
uniform float p_metallic_intensity;
uniform sampler2D t_roughness_map;
uniform float p_roughness_intensity;
uniform sampler2D t_ao_map;
uniform float p_ao_intensity;

// lights
uniform vec3 lightPositions[1];
uniform vec3 lightColors[1];

uniform vec3 camPos;

const float PI = 3.14159265359;

// -------------------------------
// tangent-normals to world-space.
vec3 getNormalFromMap()
{
    vec3 tangentNormal = texture2D(t_normal_map, f_tex_uv * 5.0).xyz * 2.0 - 1.0;

    vec3 Q1  = dFdx(f_world_pos);
    vec3 Q2  = dFdy(f_world_pos);
    vec2 st1 = dFdx(f_tex_uv * 5.0);
    vec2 st2 = dFdy(f_tex_uv * 5.0);

    vec3 N   = normalize(f_normal);
    vec3 T  = normalize(Q1*st2.t - Q2*st1.t);
    vec3 B  = -normalize(cross(N, T));
    mat3 TBN = mat3(T, B, N);

    return normalize(TBN * tangentNormal);
}
// ----------------------------------------------------------------------------
float DistributionGGX(vec3 N, vec3 H, float roughness)
{
    float a = roughness*roughness;
    float a2 = a*a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH*NdotH;

    float nom   = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;

    return nom / denom;
}
// ----------------------------------------------------------------------------
float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r*r) / 8.0;

    float nom   = NdotV;
    float denom = NdotV * (1.0 - k) + k;

    return nom / denom;
}
// ----------------------------------------------------------------------------
float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);

    return ggx1 * ggx2;
}
// ----------------------------------------------------------------------------
vec3 fresnelSchlick(float cosTheta, vec3 F0)
{
    return F0 + (1.0 - F0) * pow(clamp(1.0 - cosTheta, 0.0, 1.0), 5.0);
}
// ----------------------------------------------------------------------------
void main()
{	
    vec3 albedo     = pow(texture2D(t_albedo, f_tex_uv * 5.0).rgb, vec3(2.2)) * p_albedo_intensity;
    float metallic  = texture2D(t_metallic_map, f_tex_uv * 5.0).r * p_metallic_intensity;
    float roughness = texture2D(t_roughness_map, f_tex_uv * 5.0).r * p_roughness_intensity;
    float ao        = texture2D(t_ao_map, f_tex_uv * 5.0).r * p_ao_intensity;

    vec3 N = getNormalFromMap();
    vec3 V = normalize(camPos - f_world_pos);

    // calculate reflectance at normal incidence; if dia-electric (like plastic) use F0 
    // of 0.04 and if it's a metal, use the albedo color as F0 (metallic workflow)    
    vec3 F0 = vec3(0.04); 
    F0 = mix(F0, albedo, metallic);

    // reflectance equation
    vec3 Lo = vec3(0.0);
    for(int i = 0; i < 1; ++i) 
    {
        // calculate per-light radiance
        vec3 L = normalize(lightPositions[i] - f_world_pos);
        vec3 H = normalize(V + L);
        float distance = length(lightPositions[i] - f_world_pos);
        float attenuation = 1.0 / (distance * distance);
        vec3 radiance = lightColors[i] * attenuation;

        // Cook-Torrance BRDF
        float NDF = DistributionGGX(N, H, roughness);   
        float G   = GeometrySmith(N, V, L, roughness);      
        vec3 F    = fresnelSchlick(max(dot(H, V), 0.0), F0);
           
        vec3 numerator    = NDF * G * F; 
        float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0) + 0.0001; // + 0.0001 to prevent divide by zero
        vec3 specular = numerator / denominator;
        
        // kS is equal to Fresnel
        vec3 kS = F;
        // for energy conservation, the diffuse and specular light can't
        // be above 1.0 (unless the surface emits light); to preserve this
        // relationship the diffuse component (kD) should equal 1.0 - kS.
        vec3 kD = vec3(1.0) - kS;
        // multiply kD by the inverse metalness such that only non-metals 
        // have diffuse lighting, or a linear blend if partly metal (pure metals
        // have no diffuse light).
        kD *= 1.0 - metallic;	  

        // scale light by NdotL
        float NdotL = max(dot(N, L), 0.0);        

        // add to outgoing radiance Lo
        Lo += (kD * albedo / PI + specular) * radiance * NdotL;  // note that we already multiplied the BRDF by the Fresnel (kS) so we won't multiply by kS again
    }   
    
    // ambient lighting (note that the next IBL tutorial will replace 
    // this ambient lighting with environment lighting).
    vec3 ambient = vec3(0.03) * albedo * ao;
    
    vec3 color = ambient + Lo;

    // HDR tonemapping
    color = color / (color + vec3(1.0));
    // gamma correct
    color = pow(color, vec3(1.0/2.2)); 

    frag_color = vec4(color, 1.0);
}