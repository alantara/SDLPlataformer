#pragma once

#include "Enemy.hpp"
using namespace Entities;
using namespace Character;

namespace Entities
{
    namespace Character
    {
        class Skeleton : public Enemy
        {
        public:
            Skeleton();
            ~Skeleton();

            void update();
        };
    }
}