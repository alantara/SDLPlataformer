#pragma once

#include "Obstacle.hpp"
using namespace Entities;
using namespace Obstacles;

namespace Entities
{
    namespace Obstacles
    {
        class Barrel : public Obstacle
        {
        private:
            int weight;

        public:
            Barrel() : weight(((rand() % 1000) / 1000.0f) + 1)
            {
                physics.setW(45);
                physics.setH(64);
                sprite.setSprite("assets/barrel.png", 0, 0, 45, 64);
            }
            ~Barrel();

            void move() override
            {
                applyGravity();

                physics.setYVelocity(physics.getYVelocity() + physics.getYAcceleration() + weight);
                if (physics.getYVelocity() > 15)
                    physics.setYVelocity(15);

                physics.setXPosition(physics.getXPosition() + physics.getXVelocity());
                physics.setYPosition(physics.getYPosition() + physics.getYVelocity());
            }

            void update()
            {
                applyGravity();
                physics.setYVelocity(physics.getYVelocity() * weight);
                move();
            }
            void save(ofstream &arq)
            {
                Physics *phy = this->getPhysics();
                arq << "5" << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() << endl;
            }
        };
    }
}