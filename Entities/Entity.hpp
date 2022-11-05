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

    public:
        Entity(): Ente(){};
        ~Entity(){};

        void Inactivate() { active = false; }
        void Activate() { active = true; }

        void setPosition(int xPos, int yPos, int width, int height, int vX, int vY)
        {
            position.setPosition(xPos, yPos, width, height, vX, vY);
        }

        Position *getPosition() { return &position; }

        virtual void update() = 0;
        void render()
        {
            if (!active)
                return;

            sprite.render(position.getX(), position.getY());
        }
    };
}