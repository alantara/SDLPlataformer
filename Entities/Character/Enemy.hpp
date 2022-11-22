#pragma once

#include "Projectile.hpp"
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
            Enemy(int hp, Player* pl, Player* pl2, bool sh = false);
            ~Enemy();

            virtual Projectile* getBullet() {return nullptr;}
            bool getIsShooter() {return shooter;}

            virtual void update() = 0;
            void pursue(Player* player);
            virtual void save(ofstream &arq){};
        };
    }
}