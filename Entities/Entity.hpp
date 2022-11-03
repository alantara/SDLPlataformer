#pragma once

#include "Ente.hpp"

#include <iostream>
#include <string>
using namespace std;

#include "Sprite.hpp"
#include "Position.hpp"
using namespace Components;

namespace Entities
{
    class Entity : public Ente
    {
    protected:
        bool active;

        Position position;
        Sprite sprite;
        SDL_Rect hitbox;

    public:
        Entity(){};
        ~Entity(){};

        void Inactivate() { active = false; }
        void Activate() { active = true; }

        void setPosition(int xPos, int yPos)
        {
            position.setPosition(xPos, yPos);
        }
        void setSprite(GraphicManager *gfxM, string p, int f, int c, int w, int h, int m = 1)
        {
            sprite.setSprite(gfxM, p, f, c, w, h, m);
        }
        void setHitBox(SDL_Rect hb) { hitbox = hb; }

        const Position *getPosition() const { return &position; }
        const Sprite *getSprite() const { return &sprite; }
        const SDL_Rect *getHitBox() const { return &hitbox; }

        virtual void update() = 0;
        void render()
        {
            if (!active)
                return;

            sprite.render(position.getX(), position.getY());
        }
    };
}