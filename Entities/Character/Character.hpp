#pragma once

#include "Entity.hpp"

namespace Entities
{
    namespace Characters
    {
        class Character : public Entity
        {
        protected:
            int health;
            int vx, vy;
            int ax, ay;

        public:
            Character(GraphicManager *graphM, int x, int y) : Entity(graphM, x, y), health(5){};
            ~Character(){};

            void takeDamage() { health--; }

            int getVx() { return vx; }
            int getVy() { return vy; }

            int setVx(int v) { return vx = v; }
            int setVy(int v) { return vy = v; }

            int setAx(int v) { return ax = v; }
            int setAy(int v) { return ay = v; }

            virtual void update() = 0;
        };
    }
}