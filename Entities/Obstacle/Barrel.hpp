#pragma once

#include "Obstacle.hpp"
using namespace Entities;
using namespace Obstacles;

namespace Entities
{
    namespace Obstacles
    {
        class Barrel : public Obstacle
        {
        private:
            float weight;

        public:
            Barrel() : weight(((rand() % 1000) / 1000.0f) + 1)
            {
                entityID = 5;

                physics.setW(45);
                physics.setH(64);
                sprite.setSprite("assets/barrel.png", 0, 0, 45, 64);
            }
            ~Barrel();

            void update()
            {
                applyGravity();
                physics.setYVelocity(physics.getYVelocity() * weight);
                move();
            }
        };
    }
}