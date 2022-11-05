#pragma once

#include "Ente.hpp"

#include "EntityList.hpp"
using namespace Lists;

#include "Player.hpp"
using namespace Entities;
using namespace Characters;

//#include "CollisionManager.hpp"
#include "GraphicManager.hpp"
#include "CollisionManager.hpp"
#include "EventManager.hpp"
using namespace Managers;

namespace Levels
{
    class Level : public Ente
    {
    protected:
        EntityList entList;
        CollisionManager colManager;

        EventManager *evManager;

        Player *p1;
        Player *p2;

    public:
        Level(GraphicManager *p_graphM, EventManager *ev);
        ~Level();

        void render();
        virtual void update() = 0;

        CollisionManager getCollisionManager() { return colManager; }
    };
}