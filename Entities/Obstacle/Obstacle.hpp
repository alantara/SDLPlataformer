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
            Obstacle(GraphicManager *graphM, bool harm = false) : Entity(graphM, 0,0), isHarmful(harm) {}
            ~Obstacle(){};
        };
    }
}