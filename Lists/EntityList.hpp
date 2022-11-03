#pragma once

#include "List.hpp"

#include "Entity.hpp"
using namespace Entities;

namespace Lists
{
    class EntityList
    {
    private:
        List<Entity*> entList;

    public:
        EntityList() : entList(){};
        ~EntityList(){};

        void renderAll();
        void updateAll();
        void insert(Entity *entity);
    };
}
