#include "ObjectSystem.hpp"

void ObjectSystem::UpdateAll(float delta)
{
    for (size_t i = 0; i < object_pool.size(); i++)
        object_pool[i]->Update(delta);
}

void ObjectSystem::DrawAll(float delta)
{
    for (size_t i = 0; i < object_pool.size(); i++)
        object_pool[i]->Draw(delta);
}
