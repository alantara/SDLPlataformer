#pragma once

#include "Ente.hpp"
#include "EntityList.hpp"
#include "Map.hpp"
using namespace Lists;

#include "GraphicManager.hpp"

namespace Levels
{
    class Level : public Ente
    {
    protected:
        EntityList entList;

    public:
        Level(GraphicManager *graphM);
        ~Level();

        void render();
        virtual void update() = 0;

        void manageCollision();

        EntityList *getEntityList() { return &entList; }
    };
}