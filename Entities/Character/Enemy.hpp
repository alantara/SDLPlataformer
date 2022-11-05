#pragma once

#include "Character.hpp"

namespace Entities
{
    namespace Characters
    {
        class Enemy : public Character
        {
        protected:
            bool shooter;
        public:
            Enemy(GraphicManager *p_graphM, int hp) : Character(p_graphM, hp){};
            ~Enemy();

            virtual void update() = 0;
        };
    }
}