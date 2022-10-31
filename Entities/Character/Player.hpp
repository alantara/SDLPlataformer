#pragma once

#include "Character.hpp"

#include "EventManager.hpp"
#include "GraphicManager.hpp"

namespace Entities
{
    namespace Character
    {
        class Player : public Character
        {
        private:
            EventManager *event;

        public:
            Player(GraphicManager* graphM, EventManager *ev, int xPos, int yPos);
            ~Player();

            void update();
        };
    }
}