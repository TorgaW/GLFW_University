#include "Object.hpp"

Object::Object(float *vertices, size_t vert_num, std::string name, size_t id)
{
    //gen VBO
    glGenBuffers(1, &object_VBO);

    //gen VAO
    glGenVertexArrays(1, &object_VAO);

    //bind object VAO - start state recording
    glBindVertexArray(object_VAO);

    //bind object VBO
    glBindBuffer(GL_ARRAY_BUFFER, object_VBO);

    //fill object VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vert_num, vertices, GL_STATIC_DRAW);

    //set vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //unbind object VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //unbind VAO - stop state recording
    glBindVertexArray(0);

    object_name = name;
    object_id = id;

    object_vertices = (float*)malloc(vert_num * sizeof(float));
    memcpy(object_vertices, vertices, vert_num * sizeof(float));
}
