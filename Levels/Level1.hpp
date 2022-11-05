#pragma once

#include "Level.hpp"

#include "Plataform.hpp"

#include "Player.hpp"
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
            cout << "Level1 Initialized" << endl;
            sprite.setSprite(graphM, "assets/back.png", 0, 0, 1920, 1080);

            entList.insert(static_cast<Entity *>(player));
            entList.insert(static_cast<Entity *>(player2));

            player->setPosition(800, 450, 64, 64, 0, 0);
            player2->setPosition(100, 100, 64, 64, 0, 0);

            colManager.setPlayer(player);
            colManager.setPlayer2(player2);
            

            Plataform *plataform = new Plataform(gfx);
            plataform->setPosition(800, 700, 192, 64, 0, 0);
            plataform->setSprite(gfx, "assets/singletile.jpg", 0, 0, 257, 87, 1);

            colManager.insertObs(static_cast<Obstacle *>(plataform));
            entList.insert(static_cast<Entity *>(plataform));

        }
        ~Level1()
        {
            cout << "Level1 Destroyed" << endl;
        }

        void update()
        {
            colManager.Execute();
            entList.updateAll();
        }
    };
}