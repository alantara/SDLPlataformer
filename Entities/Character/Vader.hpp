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
                force = (rand()%3)+3;
                sprite.setSprite("assets/vader.png", 0, 0, 64, 51, 1);
                physics.setXVelocity(2);
                physics.setW(64 * sprite.getMultiplier());
                physics.setH(51 * sprite.getMultiplier());
            }
            ~Vader();

            void doDamage(Player* pl) override
            {
                pl->takeDamage(force);
            }

            void update()
            {
                if(!isActive)
                    return;

                if(health <= 0)
                {
                    Deactivate();
                    player->addScorePoints(50 + force);
                }
                move();
            }
            virtual void save(ofstream &arq)
            {
                Physics *phy = this->getPhysics();
                arq << "4" << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() << endl;
            }
        };
    }
}