#pragma once

#include "Enemy.hpp"

namespace Entities
{
    namespace Characters
    {
        class Zombie : public Enemy
        {
        public:
            Zombie();
            ~Zombie();

            void update();
        };
    }
}