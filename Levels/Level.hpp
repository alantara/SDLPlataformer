#pragma once

#include <SDL2/SDL_ttf.h>
#include <iostream>
using namespace std;

#include "Ente.hpp"
#include "Font.hpp"

#include "EntityList.hpp"
using namespace Lists;

#include "Player.hpp"
#include "Spike.hpp"
#include "Barrel.hpp"
#include "Plataform.hpp"
#include "Vader.hpp"
#include "Trooper.hpp"
#include "Maul.hpp"
using namespace Entities;
using namespace Characters;
using namespace Obstacles;

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
        Font ST;

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
        void createVader(int x, int y);

        void spikeBulkInitialize(int n, int xi, int yi, int xf, int yf);
        void plataformBulkInitialize(int n, int xi, int yi, int xf, int yf, int type = 1);
        void barrelBulkInitialize(int n, int xi, int yi, int xf, int yf);
        void vaderBulkInitialize(int n, int xi, int yi, int xf, int yf);

        void groundInitialize();
    };
}