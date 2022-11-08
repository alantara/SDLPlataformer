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
        public:
            Barrel(){};
            ~Barrel();
        };
    }
}