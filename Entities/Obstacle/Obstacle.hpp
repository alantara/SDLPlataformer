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

            const bool getHarm() const { return isHarmful; }
            virtual void update() = 0;
        };
    }
}