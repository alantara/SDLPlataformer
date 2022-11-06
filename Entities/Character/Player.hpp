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

        public:
            Player(GraphicManager *p_graphM);
            ~Player();

            void setInputSystem(EventManager *ev, SDL_Scancode l, SDL_Scancode r, SDL_Scancode j, SDL_Scancode f);
            CharacterInput getInputSystem() { return input; };

            Projectile *getBullet() { return bullet; }

            void update();
        };
    }
}