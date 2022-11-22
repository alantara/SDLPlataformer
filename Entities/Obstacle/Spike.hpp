#pragma once

#include "Obstacle.hpp"
using namespace Entities;
using namespace Obstacles;

namespace Entities
{
    namespace Obstacles
    {
        class Spike : public Obstacle
        {
        private:
            int damage;

        public:
            Spike() : Obstacle(true), damage(1)
            {

                physics.setW(32);
                physics.setH(22);
                setSprite("assets/spike.png", 0, 0, 32, 22, 1);
            }
            ~Spike();

            void update()
            {
                applyGravity();

                move();
            }
            void save(ofstream &arq)
            {
                Physics *phy = this->getPhysics();
                arq << "6" << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() << endl;
            }
        };
    }
}