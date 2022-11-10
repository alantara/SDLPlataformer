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
        Level1(EventManager *ev, Player *player, Player *player2) : Level(ev)
        {
            initialize(player, player2);
        }
        ~Level1()
        {
            cout << "Level1 Destroyed" << endl;
        }

        void initialize(Player *player, Player *player2)
        {
            cout << "Level1 Initialized" << endl;
            sprite.setSprite(gfx, "assets/back.png", 0, 0, 1920, 1080);
            groundInitialize();

            entList.insert(static_cast<Entity *>(player));
            entList.insert(static_cast<Entity *>(player2));
            entList.insert(static_cast<Entity *>(player->getBullet()));
            entList.insert(static_cast<Entity*>(player2->getBullet()));

            player->setPhysics(800, 450, 64, 64, 0, 0, 0, 0);
            player2->setPhysics(900, 450, 64, 64, 0, 0, 0, 0);

            colManager.setPlayer(player);
            colManager.setPlayer2(player2);

            Trooper *trp = new Trooper(player, player2);
            trp->setPhysics(400, 450, 64, 64, 2, 0, 0, 0);
            entList.insert(static_cast<Entity *>(trp));
            entList.insert(static_cast<Entity*>(trp->getBullet()));
            colManager.insertEnemy(static_cast<Enemy *>(trp));

            //spikeBulkInitialize(3, 0, 200, 1700, 600);

            Plataform *plataform = new Plataform();
            plataform->setPhysics(0, 700, 257, 87, 0, 0, 0, 0);
            plataform->setSprite("assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform));
            entList.insert(static_cast<Entity *>(plataform));

            Plataform *plataform2 = new Plataform();
            plataform2->setPhysics(257, 700, 257, 87, 0, 0, 0, 0);
            plataform2->setSprite("assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform2));
            entList.insert(static_cast<Entity *>(plataform2));

            Plataform *plataform3 = new Plataform();
            plataform3->setPhysics(514, 700, 257, 87, 0, 0, 0, 0);
            plataform3->setSprite("assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform3));
            entList.insert(static_cast<Entity *>(plataform3));

            Plataform *plataform4 = new Plataform();
            plataform4->setPhysics(771, 700, 257, 87, 0, 0, 0, 0);
            plataform4->setSprite("assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform4));
            entList.insert(static_cast<Entity *>(plataform4));

            Plataform *plataform5 = new Plataform();
            plataform5->setPhysics(1028, 700, 257, 87, 0, 0, 0, 0);
            plataform5->setSprite("assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform5));
            entList.insert(static_cast<Entity *>(plataform5));

            Plataform *plataform6 = new Plataform();
            plataform6->setPhysics(1028, 613, 257, 87, 0, 0, 0, 0);
            plataform6->setSprite("assets/singletile.jpg", 0, 0, 257, 87, 1);

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