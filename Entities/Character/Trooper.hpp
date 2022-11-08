#pragma once

#include "Enemy.hpp"

namespace Entities
{
    namespace Characters
    {
        class Trooper : public Enemy
        {
        private:
            Projectile* bullet;

        public:
            Trooper(GraphicManager *p_graphM, Player* pl, Player* pl2) : Enemy(p_graphM, 4, pl, pl2), bullet(new Projectile(p_graphM, false))
            {
                physics.setXVelocity(2);
                sprite.setSprite(gfx, "assets/trooper.png", 0, 0, 64, 43);
            }
            ~Trooper();

            Projectile* getBullet() {return bullet;}

            void update()
            {
                pursue(player);
                pursue(player2);
                if(rand()%20 == 0)
                    bullet->fire(this->getPhysics()->getXPosition(), this->getPhysics()->getYPosition()+20, moveDir);
                move();
            }
        };
    }
}