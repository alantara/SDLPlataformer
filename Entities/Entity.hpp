#pragma once

#include "Ente.hpp"

#include "Position.hpp"
using namespace Components;

namespace Entities
{
    class Entity : public Ente
    {
    protected:
        bool active;
        Position position;
        bool isGrounded;

    public:
        Entity(GraphicManager *p_graphM) : Ente(p_graphM), active(true){};
        ~Entity(){};

        void Deactivate() { active = false; }
        void Activate() { active = true; }

        void setPosition(int xPos, int yPos, int width, int height, int vX, int vY)
        {
            position.setPosition(xPos, yPos, width, height, vX, vY);
        }
        Position *getPosition() { return &position; }

        void setIsGrounded(bool v){isGrounded = v;}
        const bool getIsGrounded() const {return isGrounded;}

        virtual void update() = 0;
        void applyGravity() { position.setVY(5);}
        void render()
        {
            if (!active)
                return;

            sprite.render(gfx, position.getX(), position.getY());
        }
    };
}