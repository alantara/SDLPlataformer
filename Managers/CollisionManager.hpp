#pragma once

#include <vector>
#include <list>
using namespace std;

#include "Player.hpp"
#include "Enemy.hpp"
#include "Obstacle.hpp"
#include "Plataform.hpp"
using namespace Entities;
using namespace Characters;
using namespace Obstacles;

namespace Managers
{
    class CollisionManager
    {
    private:
        vector<Enemy *> LIs;
        list<Obstacle *> LOs;
        list<Plataform *> LPs;

    public:
        CollisionManager();
        ~CollisionManager();

        int isColliding(Character *ch, Entity *ent);
        void handleCollision(Player *pl);

        list<Plataform *> *getListPlataforms() { return &LPs; }
    };
}