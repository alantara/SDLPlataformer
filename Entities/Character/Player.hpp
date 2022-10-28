#pragma once

#include "Sprite.hpp"
#include "Character.hpp"
using namespace Entities;
using namespace Character;

namespace Entities
{
    namespace Character
    {
        class Player : public Character
        {
        public:
            Player();
            ~Player();

            void update();
        };
    }
}