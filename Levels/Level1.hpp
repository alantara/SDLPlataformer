#pragma once

#include "Level.hpp"

#include "Plataform.hpp"

#include "Player.hpp"
#include "Trooper.hpp"
#include "Spike.hpp"
using namespace Entities;
using namespace Characters;

#include <iostream>
using namespace std;

namespace Levels
{
    class Level1 : public Level
    {
    public:
        Level1(GraphicManager *graphM, EventManager *ev, Player *player, Player *player2) : Level(graphM, ev)
        {
            initialize(player, player2, graphM);
        }
        ~Level1()
        {
            cout << "Level1 Destroyed" << endl;
        }

        void initialize(Player *player, Player *player2, GraphicManager *graphM)
        {
            cout << "Level1 Initialized" << endl;
            sprite.setSprite(graphM, "assets/back.png", 0, 0, 1920, 1080);

            entList.insert(static_cast<Entity *>(player));
            entList.insert(static_cast<Entity *>(player2));
            entList.insert(static_cast<Entity *>(player->getBullet()));

            player->setPhysics(800, 450, 64, 64, 0, 0, 0, 0);
            player2->setPhysics(900, 450, 64, 64, 0, 0, 0, 0);

            colManager.setPlayer(player);
            colManager.setPlayer2(player2);

            Trooper *trp = new Trooper(gfx);
            trp->setPhysics(400, 450, 64, 64, 2, 0, 0, 0);
            entList.insert(static_cast<Entity *>(trp));
            colManager.insertEnemy(static_cast<Enemy *>(trp));

            Spike *spk = new Spike(gfx);
            spk->setPhysics(0, 400, 64, 43, 0, 0, 0, 0);

            colManager.insertObs(static_cast<Obstacle *>(spk));
            entList.insert(static_cast<Entity *>(spk));

            Plataform *plataform = new Plataform(gfx);
            plataform->setPhysics(0, 700, 257, 87, 0, 0, 0, 0);
            plataform->setSprite(gfx, "assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform));
            entList.insert(static_cast<Entity *>(plataform));

            Plataform *plataform2 = new Plataform(gfx);
            plataform2->setPhysics(257, 700, 257, 87, 0, 0, 0, 0);
            plataform2->setSprite(gfx, "assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform2));
            entList.insert(static_cast<Entity *>(plataform2));

            Plataform *plataform3 = new Plataform(gfx);
            plataform3->setPhysics(514, 700, 257, 87, 0, 0, 0, 0);
            plataform3->setSprite(gfx, "assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform3));
            entList.insert(static_cast<Entity *>(plataform3));

            Plataform *plataform4 = new Plataform(gfx);
            plataform4->setPhysics(771, 700, 257, 87, 0, 0, 0, 0);
            plataform4->setSprite(gfx, "assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform4));
            entList.insert(static_cast<Entity *>(plataform4));

            Plataform *plataform5 = new Plataform(gfx);
            plataform5->setPhysics(1028, 700, 257, 87, 0, 0, 0, 0);
            plataform5->setSprite(gfx, "assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform5));
            entList.insert(static_cast<Entity *>(plataform5));

            Plataform *plataform6 = new Plataform(gfx);
            plataform6->setPhysics(1028, 613, 257, 87, 0, 0, 0, 0);
            plataform6->setSprite(gfx, "assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform6));
            entList.insert(static_cast<Entity *>(plataform6));
        }

        void update()
        {
            colManager.Execute();
            entList.updateAll();
        }
    };
}