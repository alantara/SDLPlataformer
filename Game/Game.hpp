#pragma once

//#include "Player.hpp"
#include "Level1.hpp"
//#include "Level2.hpp"
//#include "Menu.hpp"
#include "GraphicManager.hpp"
#include "EventManager.hpp"

using namespace Levels;

//using namespace Levels;

class Game 
{
private:
    bool isRunning;
    //Player player;
    Level1 lvl1;
    //Level2 lvl2;
    //Menu menu;
    GraphicManager gfx;
    EventManager events;

public:
    Game();
    ~Game();

    void init();
    void run();
    void update();
    void render();
};