#pragma once

#include "Ente.hpp"

#include "EntityList.hpp"
using namespace Lists;

#include "Player.hpp"
using namespace Entities;
using namespace Characters;

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

        Ground *gnd;
        Player *p1;
        Player *p2;

    public:
        Level(EventManager *ev);
        ~Level();

        void render();
        virtual void update() = 0;
        void clean();

        void createSpike();
        void createPlataform();
        void createTrooper();
        void createVader();
        void createMaul();

        void spikeBulkInitialize(int n, int xi, int yi, int xf, int yf);
        void plataformBulkInitialize(int n, int xi, int yi, int xf, int yf);
        void groundInitialize();
    };
}