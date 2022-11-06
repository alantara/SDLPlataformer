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
        Projectile(GraphicManager *p_graphM, bool ips) : Entity(p_graphM), isPlayerShooted(ips)
        {
            sprite.setSprite(gfx, "assets/laser.png", 0, 0, 64, 13, 1);
        }
        ~Projectile(){};

        void fire(int x, int y, int dir)
        {
            physics.setPosition(x, y);
            physics.setVelocity(80 * dir, -2);
        }

        void update()
        {
            move(3);
        }
    };
}