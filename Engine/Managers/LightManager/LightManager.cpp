#include "LightManager.hpp"

P_DirectionalLight *LightManager::CreatePhongDirectionalLight(const glm::vec3 &dir, const glm::vec3 &color, float intensity)
{
    if (phong_light_pool.size() >= max_lights)
        return nullptr;
    PhongLight *t = new PhongLight(LightType::Directional, {0.0f, 0.0f, 0.0f}, dir, color, intensity, 0.0f, (last_light_id++));
    phong_light_pool.push_back(t);
    return t;
}

PBR_DirectionalLight *LightManager::CreatePBRDirectionalLight(const glm::vec3 &dir, const glm::vec3 &color, float intensity)
{
    if (pbr_dir_light_pool.size() + pbr_pnt_light_pool.size() + pbr_spt_light_pool.size() >= max_lights)
        return nullptr;
    PBRLight *t = new PBRLight(LightType::Directional, {0.0f, 0.0f, 0.0f}, dir, color, intensity, 0.0f, (last_light_id++));
    pbr_dir_light_pool.push_back(t);
    return t;
}

PBR_PointLight *LightManager::CreatePBRPointLight(const glm::vec3 &pos, const glm::vec3 &color, float attenuation)
{
    if (pbr_dir_light_pool.size() + pbr_pnt_light_pool.size() + pbr_spt_light_pool.size() >= max_lights)
        return nullptr;
    PBRLight *t = new PBRLight(LightType::Point, pos, {0.0f, 0.0f, 0.0f}, color, attenuation, 0.0f, (last_light_id++));
    pbr_pnt_light_pool.push_back(t);
    return t;
}

PBR_SpotLight *LightManager::CreatePBRSpotLight(const glm::vec3 &pos, const glm::vec3 &dir, const glm::vec3 &color, float intensity, float cut_off, float outer_cut_off)
{
    if (pbr_dir_light_pool.size() + pbr_pnt_light_pool.size() + pbr_spt_light_pool.size() >= max_lights)
        return nullptr;
    PBRLight *t = new PBRLight(LightType::Spot, pos, dir, color, intensity, cut_off, (last_light_id++));
    t->outer_cut_off = outer_cut_off;
    pbr_spt_light_pool.push_back(t);
    return t;
}

// P_PointLight *LightManager::CreatePhongPointLight(const glm::vec3 &pos, const glm::vec3 &color, float intensity)
// {
//     if (phong_light_pool.size() >= max_lights)
//         return nullptr;
//     PhongLight *t = new PhongLight(LightType::Point, pos, {0.0f, 0.0f, 0.0f}, color, intensity, (last_light_id++));
//     phong_light_pool.push_back(t);
//     return t;
// }

// P_SkyLight *LightManager::CreatePhongSkyLight(const glm::vec3 &color, float intensity)
// {
//     if (phong_light_pool.size() >= max_lights)
//         return nullptr;
//     PhongLight *t = new PhongLight(LightType::Point, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, color, intensity, (last_light_id++));
//     phong_light_pool.push_back(t);
//     return t;
// }
