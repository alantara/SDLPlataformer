#pragma once

#include "Level.hpp"

#include <iostream>
using namespace std;

namespace Levels
{
    class Level1 : public Level
    {
    public:
        Level1(GraphicManager *graphM) : Level(graphM)
        {
            cout << "Level1 Initialized" << endl;
        }
        ~Level1()
        {
            cout << "Level1 Destroyed" << endl;
        }

        void update(){};
    };
}