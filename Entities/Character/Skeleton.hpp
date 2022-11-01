#pragma once

#include "Enemy.hpp"

namespace Entities
{
    namespace Characters
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