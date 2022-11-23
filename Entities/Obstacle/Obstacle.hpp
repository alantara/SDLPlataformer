#pragma once

#include "Entity.hpp"
using namespace Entities;

namespace Entities
{
    namespace Obstacles
    {
        class Obstacle : public Entity
        {
        protected:
            bool isHarmful;

        public:
            Obstacle(bool harm = false) : isHarmful(harm) {
                type = "Obstacle";
            }
            ~Obstacle(){};

            virtual const int getDamage() const {return 0;}
            const bool getHarm() const { return isHarmful; }
            virtual void update() = 0;
            virtual void save(ofstream &arq){};
        };
    }
}