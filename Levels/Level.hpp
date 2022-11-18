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

        int getEnemySize() { return entList.getEnemySize(); }

        void createSpike(int x, int y);
        void createPlataform(int x, int y, int type = 1);
        void createBarrel(int x, int y);
        void createTrooper(int x, int y);
        void createVader(int x, int y);
        void createMaul(int x, int y);

        void spikeBulkInitialize(int n, int xi, int yi, int xf, int yf);
        void plataformBulkInitialize(int n, int xi, int yi, int xf, int yf, int type = 1);
        void barrelBulkInitialize(int n, int xi, int yi, int xf, int yf);
        void trooperBulkInitialize(int n, int xi, int yi, int xf, int yf);
        void vaderBulkInitialize(int n, int xi, int yi, int xf, int yf);
        void maulBulkInitialize(int n, int xi, int yi, int xf, int yf);

        void groundInitialize();
    };
}