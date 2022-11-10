#pragma once

#include "Level.hpp"

namespace Levels
{
    class Level2 : public Level
    {
    public:
        Level2(EventManager *ev, Player *player, Player *player2) : Level(ev){};
        ~Level2(){};

        void update(){};
        void render(){};
    };
}