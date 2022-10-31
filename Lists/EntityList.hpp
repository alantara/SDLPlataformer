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
        List<Entity *> EntList;

    public:
        EntityList() : EntList(){};
        ~EntityList(){};

        void renderAll(SDL_Renderer *renderer);
        void updateAll();
        void insert(Entity *entity);
    };
}
