
#pragma once

#include "Obstacle.hpp"
using namespace Entities;
using namespace Obstacles;

namespace Entities
{
    class Plataform : public Obstacle
    {
    private:

    public:
        Plataform();
        ~Plataform();

        void update();
    };
}