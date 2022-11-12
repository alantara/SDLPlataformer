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
            Trooper(Player* pl, Player* pl2) : Enemy(1, pl, pl2, true), bullet(new Projectile(false))
            {
                physics.setXVelocity(1);
                physics.setW(64);
                physics.setH(53);
                sprite.setSprite(gfx, "assets/trooper.png", 0, 0, 64, 53);
            }
            ~Trooper();

            Projectile* getBullet() override {return bullet;}

            void update()
            {
                if(!isActive)
                    return;

                if(health <= 0)
                    Deactivate();
                //pursue(player);
                //pursue(player2);
                if(rand()%50 == 0){
                    bullet->fire(this->getPhysics()->getXPosition(), this->getPhysics()->getYPosition()+20, physics.getMoveDirection());
                }
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