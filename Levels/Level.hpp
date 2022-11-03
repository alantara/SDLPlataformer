#pragma once

#include "Ente.hpp"

#include "EntityList.hpp"
using namespace Lists;

//#include "CollisionManager.hpp"
#include "GraphicManager.hpp"
#include "EventManager.hpp"
using namespace Managers;

namespace Levels
{
    class Level : public Ente
    {
    protected:
        GraphicManager *gfx;
        EventManager *events;

        EntityList entList;
        Sprite bg;
        // CollisionManager colManager;

    public:
        Level(GraphicManager *graphM, EventManager *ev);
        ~Level();

        void render();
        virtual void update() = 0;

        void manageCollision();

        EntityList *getEntityList() { return &entList; }
        // CollisionManager *getCollisionManager() { return &colManager; }
    };
}