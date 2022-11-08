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
            int moveDir;

        public:
            Character(int hp) : health(hp), moveDir(1){};
            ~Character(){};

            void setHealth(int hp) { health = hp; }
            const int getHealth() const { return health; }
            void takeDamage() { health--; }
            
            const int getMoveDirection() const { return moveDir; }

            virtual void update() = 0;
        };
    }
}