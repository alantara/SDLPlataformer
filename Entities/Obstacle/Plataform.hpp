
#pragma once

#include "Obstacle.hpp"
using namespace Entities;
using namespace Obstacles;

namespace Entities
{
    class Plataform : public Obstacle
    {
    private:
        bool floating;
        int type;

    public:
        Plataform(int tp = 1, bool fl = false);
        ~Plataform();

        int getType() { return type; }

        void update();
        void save(ofstream &arq)
        {
            Physics *phy = this->getPhysics();
            arq << "7" << " " << this->getType() << " " << (this->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() << endl;
        }
    };
}