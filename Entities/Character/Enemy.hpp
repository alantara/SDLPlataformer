#pragma once

#include "Character.hpp"

namespace Entities
{
    namespace Characters
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