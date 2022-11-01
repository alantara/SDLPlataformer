#pragma once

#include "Ente.hpp"
#include "Sprite.hpp"
#include <iostream>
#include <string>

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
        Entity(GraphicManager *graphM, int xpos, int ypos) : Ente(graphM),
                                                             sprite(gfx->getRenderer(), "assets/texture.png", 8, 8, 0, 0, 8),
                                                             x(xpos), 
                                                             y(ypos),
                                                             active(true), 
                                                             hitbox({x, y, sprite.getWidth(), sprite.getHeight()}) {}
        ~Entity(){};

        int getX() { return x; }
        void setX(int i) { x = i; }
        int getY() { return y; }
        void setY(int i) { y = i; }

        void Inactivate() { active = false; }
        void Activate() { active = true; }

        Sprite *getSprite() { return &sprite; }

        SDL_Rect *getHitBox() { return &hitbox; }

        virtual void update() = 0;
        void render()
        {
            if (!active)
                return;
            
            sprite.renderCharacters(gfx->getRenderer(), x, y);
        }
    };
}