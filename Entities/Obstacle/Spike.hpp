#pragma once

#include "Obstacle.hpp"
using namespace Entities;
using namespace Obstacles;

namespace Entities
{
    namespace Obstacles
    {
        class Spike : public Obstacle
        {
        public:
            Spike() : Obstacle(true) 
            {
                physics.setW(32);
                physics.setH(22);
                setSprite("assets/spike.png", 0, 0, 32, 22, 1);
            }
            ~Spike();

            void update()
            {
                applyGravity();

                move();
            }
        };
    }
}