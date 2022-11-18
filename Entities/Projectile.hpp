#pragma once

#include "Entity.hpp"
#include <iostream>
using namespace std;

namespace Entities
{
    class Projectile : public Entity
    {
    private:
        bool isPlayerShooted;

    public:
        Projectile(bool ips) : isPlayerShooted(ips)
        {
            Deactivate();
            physics.setW(48);
            physics.setH(10);
            sprite.setSprite("assets/laser.png", 0, 0, 48, 10, 1);
        }
        ~Projectile(){};

        void fire(int x, int y, int dir)
        {
            if (!isActive)
            {
                Activate();
                physics.setPosition(x, y);
                physics.setVelocity(80 * dir, -2);
            }
        }

        void update()
        {
            if (isActive)
            {
                move();
                if(physics.getXPosition() < -100 || physics.getXPosition() > GraphicManager::getWidth() + 100)
                    Deactivate();
            }
        }
    };
}