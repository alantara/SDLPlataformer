#pragma once

//#include "Player.hpp"
//#include "Level1.hpp"
//#include "Level2.hpp"
//#include "Menu.hpp"
#include "GraphicManager.hpp"
#include "EventManager.hpp"
#include "Sprite.hpp"
#include "Map.hpp"
#include "EntityList.hpp"
using namespace Lists;
//using namespace Levels;

class Game 
{
private:
    bool isRunning;
    //Player player;
    //Level1 lvl1;
    //Level2 lvl2;
    //Menu menu;
    GraphicManager gfx;
    EventManager events;
    Map *map;

public:
    Game();
    ~Game();

    void init();
    void run();
    void update();
    void render();
};