#pragma once

#include "Enemy.hpp"

namespace Entities
{
    namespace Characters
    {
        class Trooper : public Enemy
        {
        public:
            Trooper(GraphicManager *p_graphM) : Enemy(p_graphM, 4)
            {
                physics.setXVelocity(2);
                sprite.setSprite(gfx, "assets/trooper.png", 0, 0, 64, 43);
            }
            ~Trooper();

            void update()
            {
                move();
            }
        };
    }
}