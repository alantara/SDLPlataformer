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
            Obstacle(GraphicManager *graphM, int dmg = 0) : Entity(graphM), damage(dmg) {}
            ~Obstacle(){};
        };
    }
}