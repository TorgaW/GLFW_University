#ifndef DB31B06F_B77B_4F96_B3A2_C1CAC6AF9936
#define DB31B06F_B77B_4F96_B3A2_C1CAC6AF9936

#include "../Object/Object.hpp"
#include <vector>
#include <algorithm>

class ObjectSystem
{
private:
    static inline std::vector<Object*> object_pool {};
    static inline size_t object_last_id {0};
public:
    template<class T>
    static T *CreateObject(float *vertices, size_t vert_num, std::string name)
    {
        T *t_obj = new T(vertices, vert_num, name, (object_last_id++));
        object_pool.push_back(t_obj);
        return t_obj;
    };

    template<class T>
    static T *CreateObject(std::string name)
    {
        T *t_obj = new T(name, (object_last_id++));
        object_pool.push_back(t_obj);
        return t_obj;
    };

    template<class T>
    static T *CreateObject(std::string path_to_file, std::string name)
    {
        T *t_obj = new T(path_to_file, name, (object_last_id++));
        object_pool.push_back(t_obj);
        return t_obj;
    };

    template<class T>
    static T *FindObject(std::string obj_name)
    {
        auto t = std::find_if(object_pool.begin(), object_pool.end(), [&](Object *optr)
        {
            return optr->GetName() == obj_name;
        });
        if(t != object_pool.end())
            return t;
        return nullptr;
    }

    static void UpdateAll(float delta);
    static void DrawAll(float delta);

public:
    ObjectSystem(){};
    ~ObjectSystem(){};
};


#endif /* DB31B06F_B77B_4F96_B3A2_C1CAC6AF9936 */
