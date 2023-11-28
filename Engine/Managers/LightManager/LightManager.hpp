#ifndef BFA20110_5DC2_437D_A710_6D0C03E3E94D
#define BFA20110_5DC2_437D_A710_6D0C03E3E94D

#include "../../Light/Phong/PhongLight.hpp"
#include "../../Light/PBR/PBRLight.hpp"
#include <vector>

class LightManager
{
private:
    static inline std::vector<PhongLight *> phong_light_pool;
public:
    static inline std::vector<PBRLight *> pbr_dir_light_pool;
    static inline std::vector<PBRLight *> pbr_pnt_light_pool;
    static inline std::vector<PBRLight *> pbr_spt_light_pool;
    static inline int max_lights{256};
    static inline size_t last_light_id{0};

public:
    static inline std::vector<PhongLight *> GetPhongLightPool() { return phong_light_pool; };

public:
    /**
     * @brief Create a Phong Directional Light object
     *
     * @param dir light direction
     * @param color light color
     * @param intensity light intensity
     *
     * @return P_DirectionalLight*
     */
    static P_DirectionalLight *CreatePhongDirectionalLight(const glm::vec3 &dir, const glm::vec3 &color, float intensity);

    /**
     * @brief [[DEPRICATED]] Create a Phong Point Light object
     *
     * @param pos light position
     * @param color light color
     * @param intensity light intensity
     *
     * @return P_PointLight* [[DEPRICATED]]
     */
    static void CreatePhongPointLight(const glm::vec3 &pos, const glm::vec3 &color, float intensity){};

    /**
     * @brief [[DEPRICATED]] Create a Phong Sky Light object
     *
     * @param color light color
     * @param intensity light intensity
     * @return P_SkyLight* [[DEPRICATED]]
     */
    static void CreatePhongSkyLight(const glm::vec3 &color, float intensity){};


    //PBR SECTION

    static PBR_DirectionalLight *CreatePBRDirectionalLight(const glm::vec3 &dir, const glm::vec3 &color, float intensity);
    static PBR_PointLight *CreatePBRPointLight(const glm::vec3 &pos, const glm::vec3 &color, float attenuation);
    static PBR_SpotLight *CreatePBRSpotLight(const glm::vec3 &pos, const glm::vec3 &dir, const glm::vec3 &color, float intensity, float cut_off, float outer_cut_off);
    
    /////////////


    static inline void UpdateLights(float delta_t)
    {
        for (auto &&i : phong_light_pool)
        {
            i->Update(delta_t);
        }
        for (auto &&i : pbr_dir_light_pool)
        {
            i->Update(delta_t);
        }
        for (auto &&i : pbr_pnt_light_pool)
        {
            i->Update(delta_t);
        }
        for (auto &&i : pbr_spt_light_pool)
        {
            i->Update(delta_t);
        }
    };

public:
    LightManager(){};
    ~LightManager(){};
};

#endif /* BFA20110_5DC2_437D_A710_6D0C03E3E94D */
