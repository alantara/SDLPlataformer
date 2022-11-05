#pragma once

#include "Enemy.hpp"

namespace Entities
{
    namespace Characters
    {
        class Vader : public Enemy
        {
        public:
            Vader(GraphicManager *p_graphM, int hp) : Enemy(p_graphM, hp){};
            ~Vader();

            void update();
        };
    }
}