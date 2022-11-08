#pragma once

#include "Enemy.hpp"
#include "Player.hpp"

namespace Entities
{
    namespace Characters
    {
        class Vader : public Enemy
        {
        public:
            Vader(GraphicManager *p_graphM, int hp, Player* pl, Player* pl2) : Enemy(p_graphM, hp, pl, pl2){};
            ~Vader();

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