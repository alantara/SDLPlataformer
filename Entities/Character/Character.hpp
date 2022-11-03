#pragma once

#include "Entity.hpp"

#include "Physics.hpp"
using namespace Components;

namespace Entities
{
    namespace Characters
    {
        class Character : public Entity
        {
        protected:
            int health;
            Physics physics;

        public:
            Character(int hp) : health(hp) {};
            ~Character(){};

            void setPhysics(int xPos, int yPos, int xVel, int yVel, int xAcc, int yAcc) 
            {
                physics.setPhysics(xPos, yPos, xVel, yVel, xAcc, yAcc);
            }
            void setHealth(int hp) { health = hp; }

            const Physics getPhysics() const { return physics; }
            const int getHealth() const { return health; }

            void takeDamage() { health--; }

            virtual void update() = 0;
        };
    }
}