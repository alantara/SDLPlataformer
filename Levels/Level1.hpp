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


            vaderBulkInitialize(3, 300, 0, GraphicManager::getInstance()->getWidth(), GraphicManager::getInstance()->getHeight() * 2 / 5);

            trooperBulkInitialize(3, 300, 0, GraphicManager::getInstance()->getWidth(), GraphicManager::getInstance()->getHeight() * 2 / 5);

            //-------------------------------------------------------------------------
            // Obstacles Initialize
            barrelBulkInitialize(3, 300, GraphicManager::getInstance()->getHeight() * 1 / 5, GraphicManager::getInstance()->getWidth(), GraphicManager::getInstance()->getHeight() * 2 / 5);

            spikeBulkInitialize(3, 300, GraphicManager::getInstance()->getHeight() * 1 / 5, GraphicManager::getInstance()->getWidth(), GraphicManager::getInstance()->getHeight() * 3 / 5);

            plataformBulkInitialize(4, 300, GraphicManager::getInstance()->getHeight() * 3 / 5, GraphicManager::getInstance()->getWidth(), GraphicManager::getInstance()->getHeight() * 4 / 5, 5);
            plataformBulkInitialize(4, 300, GraphicManager::getInstance()->getHeight() * 4 / 5, GraphicManager::getInstance()->getWidth(), GraphicManager::getInstance()->getHeight() - 100);
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