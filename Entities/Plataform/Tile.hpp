
#pragma once

#include "Plataform.hpp"

#include <string>

namespace Entities
{
    namespace Plataform
    {
        class Tile : public Plataform
        {
        public:
            Tile(int x = 0, int y = 0);
            ~Tile();

            void update();

        private:
        };
    }
}