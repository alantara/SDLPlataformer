#pragma once

#include "Obstacle.hpp"
using namespace Entities;
using namespace Obstacles;

namespace Entities
{
    namespace Obstacles
    {
        class Rock : public Obstacle
        {
        public:
            Rock();
            ~Rock();
        };
    }
}