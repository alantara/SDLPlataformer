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
            bg.setSprite(graphM, "assets/back.jpg", 0, 0, 1920, 1080);

            player->setInputSystem(events, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_W);
            player->setPosition(0, 0);
            player->setSprite(gfx, "assets/texture.png", 0, 0, 8, 8, 8);
            player->setPhysics(0, 0, 0, 0, 0, 0);

            entList.insert(static_cast<Entity *>(player));

            player2->setInputSystem(events, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_UP);
            player2->setPosition(100, 100);
            player2->setSprite(gfx, "assets/texture.png", 0, 0, 8, 8, 8);
            player2->setPhysics(0, 0, 0, 0, 0, 0);

            entList.insert(static_cast<Entity *>(player2));

            Plataform *plataform = new Plataform(true);
            plataform->setPosition(10, 300);
            plataform->setSprite(gfx, "assets/texture.png", 0, 0, 24, 8, 8);

            entList.insert(static_cast<Entity *>(plataform));
            colManager->getListPlataforms()->push_back(plataform);
        }
        ~Level1()
        {
            cout << "Level1 Destroyed" << endl;
        }

        void update()
        {
            colManager->handleCollision(player);
            entList.updateAll();
        }
    };
}