#pragma once

#include "Ente.hpp"

#include "Physics.hpp"
using namespace Components;

namespace Entities
{
    class Entity : public Ente
    {
    private:
    protected:
        bool isActive;
        bool isGrounded;

        Physics physics;

    public:
        Entity();
        ~Entity();

        void Deactivate() { isActive = false; }
        void Activate() { isActive = true; }
        bool getIsActive() { return isActive; }

        void setPhysics(int xPos, int yPos, int width, int height, int vX, int vY, int aX, int aY) { physics.setPhysics(xPos, yPos, width, height, vX, vY, aX, aY); }
        Physics *getPhysics() { return &physics; }

        void setIsGrounded(bool v) { isGrounded = v; }
        const bool getIsGrounded() const { return isGrounded; }

        virtual void update() = 0;
        void applyGravity();
        void move();
        virtual void render();
    };
}