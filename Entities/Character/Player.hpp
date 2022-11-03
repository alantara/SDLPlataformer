#pragma once

#include "Character.hpp"

#include "GraphicManager.hpp"
#include "EventManager.hpp"
using namespace Managers;

#include "CharacterInput.hpp"
#include "Sprite.hpp"
#include "Position.hpp"
using namespace Components;

#include "EntityList.hpp"
using namespace Lists;

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
            Player(bool act, int hp);
            ~Player();

            void setInputSystem(EventManager *ev, SDL_Scancode l, SDL_Scancode r, SDL_Scancode j);
            CharacterInput getInputSystem() { return input; };

            void update();
        };
    }
}