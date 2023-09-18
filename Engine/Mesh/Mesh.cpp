#include "Mesh.hpp"

Mesh::Mesh(const std::string &name, size_t id, const std::vector<float> &vbo_data, size_t indices_n)
{
    // gen VBO
    glGenBuffers(1, &mesh_VBO);
    // gen VAO
    glGenVertexArrays(1, &mesh_VAO);
    // bind object VAO - start state recording
    glBindVertexArray(mesh_VAO);
    // bind object VBO
    glBindBuffer(GL_ARRAY_BUFFER, mesh_VBO);
    // fill object VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vbo_data.size(), &vbo_data[0], GL_STATIC_DRAW);

    //* set vertex attributes *//

    // vertex attribute for position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void *)0);
    glEnableVertexAttribArray(0);
    // vertex attribute for normals
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // vertex attribute for uvs
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    //* finishing *//

    // unbind object VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // unbind VAO - stop state recording
    glBindVertexArray(0);

    //* misc *//

    mesh_name = name;
    mesh_id = id;
    mesh_indices = indices_n;
}