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
            Vader(Player* pl, Player* pl2) : Enemy(3, pl, pl2)
            {
                physics.setXVelocity(3);
                physics.setW(64);
                physics.setH(51);
                sprite.setSprite(GraphicManager::getInstance(), "assets/vader.png", 0, 0, 64, 51);
            }
            ~Vader();

            void update()
            {
                if(!isActive)
                    return;

                if(health <= 0)
                    Deactivate();
                //pursue(player);
                //pursue(player2);
                move();
            }

            void render() override
            {
                if(isActive){
                    if(physics.getMoveDirection() == 1)
                        sprite.render(gfx, physics.getXPosition(), physics.getYPosition());
                    else
                        sprite.renderFlip(gfx, physics.getXPosition(), physics.getYPosition());
                }
            }
        };
    }
}