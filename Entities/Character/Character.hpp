#pragma once

#include "Entity.hpp"
using namespace Entities;

namespace Entities
{
    namespace Character
    {
        class Character : public Entity
        {
        protected:
            int health;
        public:
            Character();
            ~Character();

            virtual void update() = 0;
        };
    }
}