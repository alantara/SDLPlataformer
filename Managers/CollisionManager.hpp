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
        Player *pl;
        Player *pl2;

    public:
        CollisionManager();
        ~CollisionManager();

        void setPlayer(Player *player) { pl = player; }
        void setPlayer2(Player *player) { pl2 = player; }
        void insertEnemy(Enemy *en) { LIs.push_back(en); }
        void insertObs(Obstacle *obs) { LOs.push_back(obs); }

        int isColliding(Entity *ent1, Entity *ent2);
        void Execute();

        void enemyCollision();
        void obsCollision();
    };
}