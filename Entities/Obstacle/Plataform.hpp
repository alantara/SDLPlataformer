
#pragma once

#include "Obstacle.hpp"
using namespace Entities;
using namespace Obstacles;

namespace Entities
{
    class Plataform : public Obstacle
    {
    public:
        Plataform(bool act);
        ~Plataform();

        void update();

    private:
    };
}