#pragma once

#include "Level.hpp"

namespace Levels
{
    class Level2 : public Level
    {
    public:
        Level2(EventManager* ev): Level(ev){};
        ~Level2(){};

        void update(){};
    };
}