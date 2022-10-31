
#pragma once

#include "Obstacle.hpp"

#include <string>

namespace Entities
{
    namespace Obstacles
    {
        class Tile : public Obstacle
        {
        public:
            Tile(GraphicManager *graphM, int x = 0, int y = 0);
            ~Tile();

            void update();

        private:
        };
    }
}