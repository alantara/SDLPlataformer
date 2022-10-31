#pragma once

#include "Ente.hpp"
#include "Sprite.hpp"
#include <iostream>

namespace Entities
{
    class Entity : public Ente
    {
    protected:
        int x;
        int y;
        Sprite sprite;
        bool active;

    public:
        Entity() : sprite(gfx->getRenderer(), "assets/texture.png", 8, 8, 0, 0, 8){};
        ~Entity(){};

        Sprite* getSprite() { return &sprite; }
        
        virtual void update() {}
        void render(SDL_Renderer *renderer)
        {
            if(active)
                sprite.render(renderer, x, y);
        }
    };
}