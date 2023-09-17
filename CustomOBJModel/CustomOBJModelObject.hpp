#ifndef C9306450_60C5_49F0_8E00_9F5A2B9AFEC9
#define C9306450_60C5_49F0_8E00_9F5A2B9AFEC9

#include "../Object/Object.hpp"

class CustomOBJModelObject : public Object
{
public:
    //called before first render
    virtual void Begin(){};

    //called every frame before 'Draw()' function
    virtual void Update(float delta_time){};

    //called every frame
    virtual inline void Draw(float delta_time)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, object_rotation_angels.x, glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, object_rotation_angels.y, glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, object_rotation_angels.z, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, object_absolute_position);
        if(object_shader_ptr != nullptr)
        {
            object_shader_ptr->setMat4("model", model);
        }
        glBindVertexArray(object_VAO);
        glDrawArrays(GL_TRIANGLES, 0, object_indicies_num);
    };

    //called before destruction
    virtual void End(){};
public:
    //load object from file path
    CustomOBJModelObject(std::string file_path, std::string name, size_t id) : Object(file_path, name, id){};
    virtual ~CustomOBJModelObject(){};
};


#endif /* C9306450_60C5_49F0_8E00_9F5A2B9AFEC9 */
