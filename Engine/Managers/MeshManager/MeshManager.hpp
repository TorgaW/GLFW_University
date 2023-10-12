#ifndef EF5C2C72_6106_45A9_AB3E_DD454E79F54C
#define EF5C2C72_6106_45A9_AB3E_DD454E79F54C

#include "../../Mesh/Mesh.hpp"
#include "../../Utils/OBJLoader/OBJLoader.hpp"

class MeshManager
{
private:
    //pool for all Mesh objects
    static inline std::vector<Mesh*> meshes_pool {};
    //simple id system
    static inline size_t last_mesh_id {0};
public:
    /**
     * @brief Create a Mesh object from .OBJ file
     * 
     * @param path_to_obj_file relative path to .obj file
     * @param mesh_name user-defined name for the mesh
     * @return Mesh* if success nullptr otherwise
     */
    static Mesh *CreateMesh(const std::string& path_to_obj_file, const std::string& mesh_name);

    /**
     * @brief Create a Mesh object from VBO array
     * 
     * @param vbo_data 
     * @param indices_n 
     * @param mesh_name
     * @return Mesh* if success nullptr otherwise
     */
    static Mesh *CreateMesh(const std::vector<float>& vbo_data, size_t indices_n, const std::string& mesh_name);

    /**
     * @brief Get the Mesh Pool vector
     * 
     * @return std::vector<Mesh*>* 
     */
    static inline std::vector<Mesh*> *GetMeshPool() { return &meshes_pool; };

public:
    MeshManager(){};
    ~MeshManager(){};
};


#endif /* EF5C2C72_6106_45A9_AB3E_DD454E79F54C */
