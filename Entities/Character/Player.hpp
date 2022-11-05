#pragma once

#include "Character.hpp"

#include "EventManager.hpp"
using namespace Managers;

#include "CharacterInput.hpp"
using namespace Components;

namespace Entities
{
    namespace Characters
    {
        class Player : public Character
        {
        private:
            EventManager *event;
            CharacterInput input;

        public:
            Player(GraphicManager *p_graphM);
            ~Player();

            void setInputSystem(EventManager *ev, SDL_Scancode l, SDL_Scancode r, SDL_Scancode j);
            CharacterInput getInputSystem() { return input; };

            void update();
        };
    }
}