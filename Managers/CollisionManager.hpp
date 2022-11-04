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

        bool isColliding(const SDL_Rect* hb1, const SDL_Rect* hb2);
        int sideColliding(Character *ch, Entity *ent2);

        void handleCollision(Player *pl);

        list<Plataform *> *getListPlataforms() { return &LPs; }
    };
}