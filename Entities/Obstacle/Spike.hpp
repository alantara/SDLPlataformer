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
                setSprite(gfx, "assets/spike.png", 0, 0, 64, 43, 1);
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