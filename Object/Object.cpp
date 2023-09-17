#include "Object.hpp"

Object::Object(std::string file_path, std::string name, size_t id)
{
    FILE *file = fopen(file_path.c_str(), "r");
    if (file == nullptr)
    {
        std::cout << "Failed to open the file !\n";
        return;
    }

    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;
    object_triangles = 0;

    while (true)
    {
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        if (strcmp(lineHeader, "v") == 0)
        {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            temp_vertices.push_back(vertex);
            object_vert_num++;
        }
        else if (strcmp(lineHeader, "f") == 0)
        {
            // std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
                                 &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                                 &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
            if (matches != 9)
            {
                printf("File can't be read. Try exporting with other options!\n");
                return;
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            object_triangles++;
            // uvIndices.push_back(uvIndex[0]);
            // uvIndices.push_back(uvIndex[1]);
            // uvIndices.push_back(uvIndex[2]);
            // normalIndices.push_back(normalIndex[0]);
            // normalIndices.push_back(normalIndex[1]);
            // normalIndices.push_back(normalIndex[2]);
        }
    }

    // int counter = 0;
    object_vert_vector.reserve(object_vert_num*3);
    // object_vertices = (float *)malloc(vertexIndices.size() * 3 * sizeof(float));
    // For each vertex of each triangle
    for (unsigned int i = 0; i < vertexIndices.size(); i++)
    {

        // Get the indices of its attributes
        unsigned int vertexIndex = vertexIndices[i];
        // unsigned int uvIndex = uvIndices[i];
        // unsigned int normalIndex = normalIndices[i];

        // Get the attributes thanks to the index
        glm::vec3 vertex = temp_vertices[vertexIndex - 1];
        // glm::vec2 uv = temp_uvs[uvIndex - 1];
        // glm::vec3 normal = temp_normals[normalIndex - 1];

        // Put the attributes in buffers
        // object_vertices[counter] = vertex.x;
        // object_vertices[counter + 1] = vertex.y;
        // object_vertices[counter + 2] = vertex.z;
        // counter += 3;
        // out_uvs.push_back(uv);
        // out_normals.push_back(normal);

        object_vert_vector.push_back(vertex.x);
        object_vert_vector.push_back(vertex.y);
        object_vert_vector.push_back(vertex.z);
        object_indicies_num += 3;
    }
    fclose(file);

    // gen VBO
    glGenBuffers(1, &object_VBO);

    // gen VAO
    glGenVertexArrays(1, &object_VAO);

    // bind object VAO - start state recording
    glBindVertexArray(object_VAO);

    // bind object VBO
    glBindBuffer(GL_ARRAY_BUFFER, object_VBO);

    // fill object VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * object_vert_vector.size(), &object_vert_vector[0], GL_STATIC_DRAW);

    // set vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // unbind object VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // unbind VAO - stop state recording
    glBindVertexArray(0);

    object_name = name;
    object_id = id;
}

Object::Object(float *vertices, size_t vert_num, std::string name, size_t id)
{
    // gen VBO
    glGenBuffers(1, &object_VBO);

    // gen VAO
    glGenVertexArrays(1, &object_VAO);

    // bind object VAO - start state recording
    glBindVertexArray(object_VAO);

    // bind object VBO
    glBindBuffer(GL_ARRAY_BUFFER, object_VBO);

    // fill object VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vert_num, vertices, GL_STATIC_DRAW);

    // set vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // unbind object VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // unbind VAO - stop state recording
    glBindVertexArray(0);

    object_name = name;
    object_id = id;

    object_vertices = (float *)malloc(vert_num * sizeof(float));
    memcpy(object_vertices, vertices, vert_num * sizeof(float));
}
