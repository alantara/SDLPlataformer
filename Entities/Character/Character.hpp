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
            void takeDamage(int dm = 1) { health -= dm; }

            virtual void update() = 0;
            virtual void save(ofstream &arq){};
        };
    }
}