
#pragma once

#include "Obstacle.hpp"
using namespace Entities;
using namespace Obstacles;

namespace Entities
{
    class Plataform : public Obstacle
    {
    private:
        bool isDefaultGround;

    public:
        Plataform(GraphicManager *p_graphM);
        ~Plataform();

        void update();
    };
}