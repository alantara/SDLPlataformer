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
            Spike(GraphicManager *p_graphM) : Obstacle(p_graphM, true) {}
            ~Spike();
        };
    }
}