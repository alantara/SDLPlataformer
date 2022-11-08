#pragma once

#include "Ente.hpp"

#include "Physics.hpp"
using namespace Components;

namespace Entities
{
    class Entity : public Ente
    {
    protected:
        bool isActive;
        bool isGrounded;

        Physics physics;

    public:
        Entity() : isActive(true), isGrounded(false){};
        ~Entity(){};

        void Deactivate() { isActive = false; }
        void Activate() { isActive = true; }

        void setPhysics(int xPos, int yPos, int width, int height, int vX, int vY, int aX, int aY)
        {
            physics.setPhysics(xPos, yPos, width, height, vX, vY, aX, aY);
        }
        Physics *getPhysics() { return &physics; }

        void setIsGrounded(bool v) { isGrounded = v; }
        const bool getIsGrounded() const { return isGrounded; }

        virtual void update() = 0;
        void applyGravity(int id = 0)
        {
            if (id == 3)
            {
                physics.setYAcceleration(1);
            }
            else
            {
                if (physics.getYVelocity() <= 0)
                    physics.setYAcceleration(3);
                else
                    physics.setYAcceleration(10);
            }
        }
        void move(int id = 0)
        {
            applyGravity(id);

            physics.setYVelocity(physics.getYVelocity() + physics.getYAcceleration());
            if (physics.getYVelocity() > 15)
                physics.setYVelocity(15);

            physics.setXPosition(physics.getXPosition() + physics.getXVelocity());
            physics.setYPosition(physics.getYPosition() + physics.getYVelocity());
        }
        virtual void render()
        {
            if (isActive)
                sprite.render(gfx, physics.getXPosition(), physics.getYPosition());
        }
    };
}