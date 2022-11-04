#pragma once

#include "Ente.hpp"

#include "EntityList.hpp"
using namespace Lists;

#include "Player.hpp"
using namespace Entities;
using namespace Characters;

//#include "CollisionManager.hpp"
#include "GraphicManager.hpp"
#include "EventManager.hpp"
#include "CollisionManager.hpp"
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
        CollisionManager *colManager;

        Player *player;
        Player *player2;

    public:
        Level(GraphicManager *graphM, EventManager *ev);
        ~Level();

        void render();
        virtual void update() = 0;

        EntityList *getEntityList() { return &entList; }
        CollisionManager *getCollisionManager() { return colManager; }
    };
}