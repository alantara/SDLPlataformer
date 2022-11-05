#pragma once

#include "Enemy.hpp"

namespace Entities
{
    namespace Characters
    {
        class Maul : public Enemy
        {
        public:
            Maul(GraphicManager *p_graphM, int hp) : Enemy(p_graphM, hp){};
            ~Maul();

            void update();
        };
    }
}