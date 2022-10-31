#pragma once

#include "Level.hpp"

namespace Levels
{
    class Level2 : public Level
    {
    public:
        Level2(GraphicManager *graphM) : Level(graphM){};
        ~Level2(){};

        void update(){};
    };
}