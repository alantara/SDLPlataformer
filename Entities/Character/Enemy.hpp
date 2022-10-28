#pragma once

#include "Character.hpp"
using namespace Entities;
using namespace Character;

namespace Entities
{
    namespace Character
    {
        class Enemy : public Character
        {
        public:
            Enemy();
            ~Enemy();

            virtual void update() = 0;
        };
    }
}