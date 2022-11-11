#pragma once

#include "Entity.hpp"

namespace Entities
{
    namespace Characters
    {
        class Character : public Entity
        {
        protected:
            int health;

        public:
            Character(int hp) : health(hp){};
            ~Character(){};

            void setHealth(int hp) { health = hp; }
            const int getHealth() const { return health; }
            void takeDamage() { health--; }

            virtual void update() = 0;
        };
    }
}