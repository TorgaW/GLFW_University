#include "MeshManager.hpp"

Mesh *MeshManager::CreateMesh(const std::string &path_to_obj_file, const std::string &mesh_name)
{
    // create vbo vector
    std::vector<float> mesh_vbo;
    //indices value
    size_t indices;
    // load vbo from file
    if (OBJLoader::FromFile(path_to_obj_file, &mesh_vbo, &indices) == false)
    {
        std::cout << "MeshManager:: Failed to create mesh from file!\n";
        return nullptr;
    }
    // create new Mesh object
    Mesh *t = new Mesh(mesh_name, last_mesh_id++, mesh_vbo, indices);
    // push back to meshes buffer
    meshes_pool.push_back(t);
    // finish
    return t;
}
