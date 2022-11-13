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

        public:
            Barrel()
            {
                physics.setW(45);
                physics.setH(64);
                sprite.setSprite("assets/barrel.png", 0, 0, 45, 64);
            }
            ~Barrel();

            void update()
            {
                applyGravity();

                move();
            }
        };
    }
}