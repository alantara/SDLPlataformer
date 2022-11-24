#pragma once

#include "Character.hpp"

#include "EventManager.hpp"
using namespace Managers;

#include "CharacterInput.hpp"
using namespace Components;

#include "Projectile.hpp"

namespace Entities
{
    namespace Characters
    {
        class Player : public Character
        {
        private:
            EventManager *event;
            CharacterInput input;

            Projectile *bullet;

            static int points;

        public:
            Player();
            ~Player();

            void reset();

            static void addScorePoints(int i) { points += i; }
            static int getScorePoints() { return points; }

            void setInputSystem(EventManager *ev, SDL_Scancode l, SDL_Scancode r, SDL_Scancode j, SDL_Scancode f);
            CharacterInput getInputSystem() { return input; };

            Projectile *getBullet() { return bullet; }

            void update();
            virtual void save(ofstream &arq)
            {
                Physics *phy = this->getPhysics();
                arq << (this->getType() == "Player1" ? 10 : 11) << " " << (this->getIsActive() ? 1 : 0) << " " << this->getHealth() << " " << this->getScorePoints() << " " << phy->getXPosition() << " " << phy->getYPosition() << " " << phy->getXVelocity() << " " << phy->getYVelocity() << endl;
            }
        };
    }
}