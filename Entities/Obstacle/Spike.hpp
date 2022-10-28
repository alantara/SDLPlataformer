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
        Spike() : Obstacle(1){}
        ~Spike();
    };
}
}