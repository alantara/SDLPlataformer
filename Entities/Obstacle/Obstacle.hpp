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
            Obstacle(GraphicManager *p_graphM, bool harm = false) : Entity(p_graphM), isHarmful(harm) {}
            ~Obstacle(){};

            const bool getHarm() const {return isHarmful;}
        };
    }
}