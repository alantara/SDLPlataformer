#pragma once

#include "Level.hpp"

#include "Plataform.hpp"

#include "Player.hpp"
#include "Trooper.hpp"
#include "Vader.hpp"
#include "Maul.hpp"
#include "Spike.hpp"
#include "Barrel.hpp"
using namespace Entities;
using namespace Characters;
using namespace Obstacles;

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
        //------------------------------------------------------------------------
        //Player initialize
            player->getPhysics()->setPosition(150, 450);
            player2->getPhysics()->setPosition(80, 450);
            entList.insert(static_cast<Entity *>(player));
            entList.insert(static_cast<Entity *>(player2));
            entList.insert(static_cast<Entity *>(player->getBullet()));
            entList.insert(static_cast<Entity*>(player2->getBullet()));
            colManager.setPlayer(player);
            colManager.setPlayer2(player2);
        //-------------------------------------------------------------------------
        //Enemies Initialize
            
            Trooper *trp2 = new Trooper(player, player2);
            trp2->getPhysics()->setPosition(379, 920);
            entList.insert(static_cast<Entity *>(trp2));
            entList.insert(static_cast<Entity*>(trp2->getBullet()));
            colManager.insertEnemy(static_cast<Enemy *>(trp2));

            Trooper *trp = new Trooper(player, player2);
            trp->getPhysics()->setPosition(900, 950);
            entList.insert(static_cast<Entity *>(trp));
            entList.insert(static_cast<Entity*>(trp->getBullet()));
            colManager.insertEnemy(static_cast<Enemy *>(trp));

            Vader *vader = new Vader(player, player2);
            vader->getPhysics()->setPosition(1500, 450);
            entList.insert(static_cast<Entity *>(vader));
            colManager.insertEnemy(static_cast<Enemy *>(vader));

            Vader *vader2 = new Vader(player, player2);
            vader2->getPhysics()->setPosition(1600, 450);
            entList.insert(static_cast<Entity *>(vader2));
            colManager.insertEnemy(static_cast<Enemy *>(vader2));

            Maul *maul = new Maul(player, player2);
            maul->getPhysics()->setPosition(1300, 450);
            entList.insert(static_cast<Entity *>(maul));
            colManager.insertEnemy(static_cast<Enemy *>(maul));
        //-------------------------------------------------------------------------
        //Obstacles Initialize
            Barrel *barrel = new Barrel();
            barrel->getPhysics()->setPosition(680, 972);
            colManager.insertObs(static_cast<Obstacle*>(barrel));
            entList.insert(static_cast<Entity*>(barrel));

            Spike *spike = new Spike();
            spike->getPhysics()->setPosition(1150, 949);
            colManager.insertObs(static_cast<Obstacle*>(spike));
            entList.insert(static_cast<Entity*>(spike));

            Plataform *plataform2 = new Plataform(5);
            plataform2->getPhysics()->setPosition(336, 948);
            colManager.insertObs(static_cast<Obstacle *>(plataform2));
            entList.insert(static_cast<Entity *>(plataform2));

            Plataform *plataform = new Plataform();
            plataform->getPhysics()->setPosition(250, 992);
            colManager.insertObs(static_cast<Obstacle *>(plataform));
            entList.insert(static_cast<Entity *>(plataform));

            Plataform *plataform3 = new Plataform();
            plataform3->getPhysics()->setPosition(1000, 992);
            colManager.insertObs(static_cast<Obstacle *>(plataform3));
            entList.insert(static_cast<Entity *>(plataform3));

            Plataform *plataform4 = new Plataform();
            plataform4->getPhysics()->setPosition(1129, 992);
            colManager.insertObs(static_cast<Obstacle *>(plataform4));
            entList.insert(static_cast<Entity *>(plataform4));

            Plataform *plataform5 = new Plataform();
            plataform5->getPhysics()->setPosition(1258, 992);
            colManager.insertObs(static_cast<Obstacle *>(plataform5));
            entList.insert(static_cast<Entity *>(plataform5));
        }

        void update()
        {
            gnd->render();
            colManager.Execute();
            entList.updateAll();
        }
    };
}