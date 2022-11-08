#pragma once

#include "Character.hpp"
#include "Player.hpp"

namespace Entities
{
    namespace Characters
    {
        class Enemy : public Character
        {
        protected:
            bool shooter;
            Player* player;
            Player* player2;

        public:
            Enemy(GraphicManager *p_graphM, int hp, Player* pl, Player* pl2);
            ~Enemy();

            virtual void update() = 0;
            void pursue(Player* player);
        };
    }
}