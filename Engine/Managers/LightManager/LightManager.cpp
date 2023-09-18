#include "LightManager.hpp"

DirectionalLight *LightManager::CreatePhongDirectionalLight(const glm::vec3 &dir, const glm::vec3 &color, float intensity)
{
    if (phong_light_pool.size() >= max_lights)
        return nullptr;
    PhongLight *t = new PhongLight(PhongLightType::Directional, {0.0f, 0.0f, 0.0f}, dir, color, intensity, (last_light_id++));
    phong_light_pool.push_back(t);
    return t;
}

PointLight *LightManager::CreatePhongPointLight(const glm::vec3 &pos, const glm::vec3 &color, float intensity)
{
    if (phong_light_pool.size() >= max_lights)
        return nullptr;
    PhongLight *t = new PhongLight(PhongLightType::Point, pos, {0.0f, 0.0f, 0.0f}, color, intensity, (last_light_id++));
    phong_light_pool.push_back(t);
    return t;
}

SkyLight *LightManager::CreatePhongSkyLight(const glm::vec3 &color, float intensity)
{
    if (phong_light_pool.size() >= max_lights)
        return nullptr;
    PhongLight *t = new PhongLight(PhongLightType::Point, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, color, intensity, (last_light_id++));
    phong_light_pool.push_back(t);
    return t;
}
