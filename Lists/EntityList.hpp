#pragma once

#include "Entity.hpp"
#include "List.hpp"
using namespace Lists;
using namespace Entities;

namespace Lists
{
class EntityList
{
private:
    List<Entity> EntList;

public:
    EntityList();
    ~EntityList();

    void renderAll();
    void insert(Entity* entity);

};
}
