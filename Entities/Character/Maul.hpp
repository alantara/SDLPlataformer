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
                darkness = (rand() % 3) + 1;
                physics.setXVelocity(((rand()% 1000)/1000.0f) + 0.401);
                physics.setW(32);
                physics.setH(64);
                sprite.setSprite("assets/maul.png", 0, 0, 61, 64);
            }
            ~Maul();

            void doDamage(Player *pl) override
            {
                pl->takeDamage(darkness);
            }

            void update()
            {
                if (!isActive)
                    return;

                if (health <= 0)
                {
                    Deactivate();
                    player->addScorePoints(10 + darkness);
                }
                move();
            }
            virtual void save(ofstream &arq)
            {
                Physics *phy = this->getPhysics();
                arq << "3"
                    << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() << " " << phy->getXVelocity() << " " << phy->getYVelocity() << endl;
            }
        };
    }
}