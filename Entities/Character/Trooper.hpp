#pragma once

#include "Enemy.hpp"

namespace Entities
{
    namespace Characters
    {
        class Trooper : public Enemy
        {
        public:
            Trooper(GraphicManager *p_graphM, int hp) : Enemy(p_graphM, hp){};
            ~Trooper();

            void update();
        };
    }
}