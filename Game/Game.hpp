#pragma once

//#include "Player.hpp"
#include "Level1.hpp"
//#include "Level2.hpp"
//#include "Menu.hpp"
#include "GraphicManager.hpp"
#include "EventManager.hpp"
#include <string>

using namespace Levels;

//using namespace Levels;

class Game 
{
private:
    bool isRunning;

    GraphicManager gfx;
    EventManager events;

    Level1 lvl1;
    //Player player;
    //Level2 lvl2;
    //Menu menu;
    

public:
    Game();
    ~Game();

    void update();
    void render();
};