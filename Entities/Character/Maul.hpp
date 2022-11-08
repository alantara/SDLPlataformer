#pragma once

#include "Enemy.hpp"
#include "Player.hpp"

namespace Entities
{
    namespace Characters
    {
        class Maul : public Enemy
        {
        public:
            Maul(int hp, Player* pl, Player* pl2) : Enemy(hp, pl, pl2){};
            ~Maul();

            void update();
            void render() override
            {
                if (isActive)
                    if(moveDir == 1)
                        sprite.render(gfx, physics.getXPosition(), physics.getYPosition());
                    else
                        sprite.renderFlip(gfx, physics.getXPosition(), physics.getYPosition());
            }
        };
    }
}