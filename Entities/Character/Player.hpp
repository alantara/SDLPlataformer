#pragma once

#include "Character.hpp"

#include "EventManager.hpp"
#include "GraphicManager.hpp"
#include "CharacterInput.hpp"

/*
#include "GraphicManager.hpp"
#include "EventManager.hpp"
using namespace Managers;

#include "CaracterInput.hpp"
#include "SpriteConstraints.hpp"
#include "Position.hpp"
using namespace Components;
*/

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
            Player(GraphicManager *graphM, EventManager *ev, CharacterInput inp, int xPos, int yPos);
            ~Player();

            void update();
        };
    }
}