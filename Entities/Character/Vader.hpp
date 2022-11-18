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
                entityID = 4;

                physics.setXVelocity(3);
                physics.setW(64);
                physics.setH(51);
                sprite.setSprite("assets/vader.png", 0, 0, 64, 51);
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
        };
    }
}