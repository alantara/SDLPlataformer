#pragma once

#include "Enemy.hpp"
#include "Player.hpp"

namespace Entities
{
    namespace Characters
    {
        class Maul : public Enemy
        {
        private:
            int darkness;

        public:
            Maul(Player *pl, Player *pl2) : Enemy(1, pl, pl2)
            {

                physics.setXVelocity(2);
                physics.setW(61);
                physics.setH(64);
                sprite.setSprite("assets/maul.png", 0, 0, 61, 64);
            }
            ~Maul();

            void update()
            {
                if (!isActive)
                    return;

                if (health <= 0)
                {
                    Deactivate();
                    player->addScorePoints(10);
                }
                // pursue(player);
                // pursue(player2);
                move();
            }
            virtual void save(ofstream &arq)
            {
                Physics *phy = this->getPhysics();
                arq << "3" << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() << endl;
            }
        };
    }
}