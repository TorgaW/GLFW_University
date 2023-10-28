#include "LightManager.hpp"

P_DirectionalLight *LightManager::CreatePhongDirectionalLight(const glm::vec3 &dir, const glm::vec3 &color, float intensity)
{
    if (phong_light_pool.size() >= max_lights)
        return nullptr;
    PhongLight *t = new PhongLight(LightType::Directional, {0.0f, 0.0f, 0.0f}, dir, color, intensity, (last_light_id++));
    phong_light_pool.push_back(t);
    return t;
}

P_PointLight *LightManager::CreatePhongPointLight(const glm::vec3 &pos, const glm::vec3 &color, float intensity)
{
    if (phong_light_pool.size() >= max_lights)
        return nullptr;
    PhongLight *t = new PhongLight(LightType::Point, pos, {0.0f, 0.0f, 0.0f}, color, intensity, (last_light_id++));
    phong_light_pool.push_back(t);
    return t;
}

P_SkyLight *LightManager::CreatePhongSkyLight(const glm::vec3 &color, float intensity)
{
    if (phong_light_pool.size() >= max_lights)
        return nullptr;
    PhongLight *t = new PhongLight(LightType::Point, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, color, intensity, (last_light_id++));
    phong_light_pool.push_back(t);
    return t;
}
