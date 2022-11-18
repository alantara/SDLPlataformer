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
            sprite.setSprite("assets/back.png", 0, 0, 1920, 1080);
            groundInitialize();
        }
        ~Level1()
        {
            cout << "Level1 Destroyed" << endl;
        }

        void initialize(Player *player, Player *player2, bool multi)
        {
            cout << "Level1 Initialized" << endl;
            entList.insert(static_cast<Entity *>(gnd));

            //------------------------------------------------------------------------
            // Player initialize
            player->getPhysics()->setPosition(150, 450);
            entList.insert(static_cast<Entity *>(player));
            entList.insert(static_cast<Entity *>(player->getBullet()));
            colManager.setPlayer(player);

            player2->getPhysics()->setPosition(80, 450);
            entList.insert(static_cast<Entity *>(player2));
            entList.insert(static_cast<Entity *>(player2->getBullet()));
            colManager.setPlayer2(player2);

            player2->Activate();
            if (!multi)
                player2->Deactivate();

            vaderBulkInitialize(3, 400, 500, 800, 600);

            trooperBulkInitialize(3, 900, 500, 1400, 600);

            //-------------------------------------------------------------------------
            // Obstacles Initialize
            barrelBulkInitialize(3, 200, 700, 1600, 800);

            spikeBulkInitialize(3, 500, 700, 800, 800);

            //"Static" plataforms

            createPlataform(0, 100, 5);
            createPlataform(0, 200, 5);
            createPlataform(0, 300, 5);
            createPlataform(0, 400, 5);
            createPlataform(0, 500, 5);

            createPlataform(GraphicManager::getInstance()->getWidth() - 50, 100, 5);
            createPlataform(GraphicManager::getInstance()->getWidth() - 50, 200, 5);
            createPlataform(GraphicManager::getInstance()->getWidth() - 50, 300, 5);
            createPlataform(GraphicManager::getInstance()->getWidth() - 50, 400, 5);
            createPlataform(GraphicManager::getInstance()->getWidth() - 50, 500, 5);

            createPlataform(1550, 900, 4);
            createPlataform(1600, 900, 5);
            createPlataform(1650, 900, 6);

            createPlataform(400, 1000);
            createPlataform(900, 1000);
            createPlataform(1500, 1000);
            createPlataform(1600, 1000);
        }

        void update()
        {
            gnd->render();
            colManager.Execute();
            entList.updateAll();
        }

        void save()
        {
            entList.save("da.txt");
        }
    };
}