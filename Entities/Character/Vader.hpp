#pragma once

#include "Enemy.hpp"
#include "Player.hpp"

namespace Entities
{
    namespace Characters
    {
        class Vader : public Enemy
        {
        private:
            int force;

        public:
            Vader(Player* pl, Player* pl2) : Enemy(3, pl, pl2)
            {
                entityID = 4;

                sprite.setSprite("assets/vader.png", 0, 0, 64, 51, 1);
                physics.setXVelocity(3);
                physics.setW(64 * sprite.getMultiplier());
                physics.setH(51 * sprite.getMultiplier());
            }
            ~Vader();

            void update()
            {
                if(!isActive)
                    return;

                if(health <= 0)
                {
                    Deactivate();
                    player->addScorePoints(50);
                }
                //pursue(player);
                //pursue(player2);
                move();
            }
        };
    }
}