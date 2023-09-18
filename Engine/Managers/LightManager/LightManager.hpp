#ifndef BFA20110_5DC2_437D_A710_6D0C03E3E94D
#define BFA20110_5DC2_437D_A710_6D0C03E3E94D

#include "../../Light/Phong/PhongLight.hpp"
#include <vector>

class LightManager
{
private:
    static inline std::vector<PhongLight *> phong_light_pool;
    static inline int max_lights{256};
    static inline size_t last_light_id{0};

public:
    static inline std::vector<PhongLight *> *GetPhongLightPool() { return &phong_light_pool; };

public:
    /**
     * @brief Create a Phong Directional Light object
     *
     * @param dir light direction
     * @param color light color
     * @param intensity light intensity
     *
     * @return DirectionalLight*
     */
    static DirectionalLight *CreatePhongDirectionalLight(const glm::vec3 &dir, const glm::vec3 &color, float intensity);

    /**
     * @brief Create a Phong Point Light object
     *
     * @param pos light position
     * @param color light color
     * @param intensity light intensity
     *
     * @return PointLight*
     */
    static PointLight *CreatePhongPointLight(const glm::vec3 &pos, const glm::vec3 &color, float intensity);

    /**
     * @brief Create a Phong Sky Light object
     *
     * @param color light color
     * @param intensity light intensity
     * @return SkyLight*
     */
    static SkyLight *CreatePhongSkyLight(const glm::vec3 &color, float intensity);

public:
    LightManager(){};
    ~LightManager(){};
};

#endif /* BFA20110_5DC2_437D_A710_6D0C03E3E94D */
