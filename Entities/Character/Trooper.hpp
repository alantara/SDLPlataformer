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
            Trooper(Player* pl, Player* pl2) : Enemy(4, pl, pl2), bullet(new Projectile(false))
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
                if(rand()%50 == 0)
                    bullet->fire(this->getPhysics()->getXPosition(), this->getPhysics()->getYPosition()+20, moveDir);
                move();
            }
            
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