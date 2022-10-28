#pragma once

#include "Enemy.hpp"
using namespace Entities;
using namespace Character;

namespace Entities
{
    namespace Character
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