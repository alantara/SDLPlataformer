#pragma once

#include "Ente.hpp"
#include "Map.hpp"

#include "EntityList.hpp"
using namespace Lists;

#include "CollisionManager.hpp"
#include "GraphicManager.hpp"
using namespace Managers;

namespace Levels
{
    class Level : public Ente
    {
    protected:
        EntityList entList;
        CollisionManager colManager;

    public:
        Level(GraphicManager *graphM);
        ~Level();

        void render();
        virtual void update() = 0;

        void manageCollision();

        EntityList *getEntityList() { return &entList; }
        CollisionManager *getCollisionManager() { return &colManager; }
    };
}