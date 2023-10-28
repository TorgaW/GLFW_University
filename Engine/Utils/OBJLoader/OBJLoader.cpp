#include "OBJLoader.hpp"

bool OBJLoader::FromFile(const std::string &path_to_file, std::vector<float> *out_vbo_data, size_t *out_indices)
{
    // using C-like file reading
    FILE *file = fopen(path_to_file.c_str(), "r");
    if (file == nullptr)
    {
        std::cout << "Failed to open the file !\n";
        return false;
    }

    // indices for vertex, uv and normal values
    std::vector<uint32_t> vi, ni, uvi;

    // temp vectors for file data
    std::vector<glm::vec3> t_vertices;
    std::vector<glm::vec3> t_normals;
    std::vector<glm::vec2> t_uvs;

    while (true)
    {
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        if (strcmp(lineHeader, "v") == 0)
        { // if vertex found, put it in the temp vert vector
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            t_vertices.push_back(vertex);
        }
        else if (strcmp(lineHeader, "vn") == 0)
        { // same as uv and vertices for normal map values
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            t_normals.push_back(normal);
        }
        else if (strcmp(lineHeader, "vt") == 0)
        { // as for vertices, put uv coordinates to temp vector
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y);
            t_uvs.push_back(uv);
        }
        else if (strcmp(lineHeader, "f") == 0)
        {
            // reading 'face' syntax of .obj file
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
            if (matches != 9)
            {
                printf("Failed to read file. Try exporting with other options.\n");
                return false;
            }
            // push back indices
            vi.push_back(vertexIndex[0]);
            vi.push_back(vertexIndex[1]);
            vi.push_back(vertexIndex[2]);
            ni.push_back(normalIndex[0]);
            ni.push_back(normalIndex[1]);
            ni.push_back(normalIndex[2]);
            uvi.push_back(uvIndex[0]);
            uvi.push_back(uvIndex[1]);
            uvi.push_back(uvIndex[2]);
        }
    }

    // close file
    fclose(file);

    // reserve memeory for vbo data
    out_vbo_data->reserve(vi.size() * 8);

    std::ofstream debf;
    debf.open("obj_loader_log.txt");

    // combine data with values and indices
    for (size_t i = 0; i < vi.size(); i++)
    {
        // in .obj file indices start with 1, so we put 'index - 1'
        //---------------------------------------------------------
        glm::vec3 v_pos = t_vertices[vi[i] - 1]; // position
        glm::vec3 v_nor = t_normals[ni[i] - 1];  // normals
        glm::vec2 v_uvs = t_uvs[uvi[i] - 1];     // uv

        // push back position
        out_vbo_data->push_back(v_pos.x);
        out_vbo_data->push_back(v_pos.y);
        out_vbo_data->push_back(v_pos.z);
        // push back normal
        out_vbo_data->push_back(v_nor.x);
        out_vbo_data->push_back(v_nor.y);
        out_vbo_data->push_back(v_nor.z);
        // push back uv
        out_vbo_data->push_back(v_uvs.x);
        out_vbo_data->push_back(v_uvs.y);

        debf << v_pos.x << "f, " << v_pos.y << "f, " << v_pos.z << "f, " 
             << v_nor.x << "f, " << v_nor.y << "f, " << v_nor.z << "f, "
             << v_uvs.x << "f, "<< v_uvs.y << "f, \n";
    }

    debf.close();

    // set number of indices
    *out_indices = vi.size();
    // finish
    return true;
}