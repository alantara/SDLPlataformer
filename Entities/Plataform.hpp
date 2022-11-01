
#pragma once

#include "Obstacle.hpp"

#include <string>

namespace Entities
{
    class Plataform : public Entity
    {
    public:
        Plataform(GraphicManager *graphM, int x = 0, int y = 0);
        ~Plataform();

        void update();

    private:
    };
}