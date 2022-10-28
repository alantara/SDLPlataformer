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
            int damage;
        public:
            Obstacle(int dmg) : damage(dmg){}
            ~Obstacle();
        };
    }
}