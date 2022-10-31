#pragma once

#include "Ente.hpp"
#include "Sprite.hpp"
#include <iostream>

using namespace std;

namespace Entities
{
    class Entity : public Ente
    {
    protected:
        int x;
        int y;
        Sprite sprite;
        bool active;
        SDL_Rect hitbox;

    public:
        Entity(GraphicManager *graphM) : Ente(graphM), sprite(gfx->getRenderer(), "assets/texture.png", 8, 8, 0, 0, 8), active(true) {}
        ~Entity(){};

        int getX() { return x; }
        int getY() { return y; }

        Sprite *getSprite() { return &sprite; }

        virtual void update() = 0;
        void render()
        {
            if (active)
            {
                sprite.render(gfx->getRenderer(), x, y);
            }
        }
    };
}