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
            Obstacle(bool harm = false) : isHarmful(harm) {}
            ~Obstacle(){};
        };
    }
}