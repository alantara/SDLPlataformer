#pragma once

#include "Player.hpp"
using namespace Entities;
using namespace Characters;

#include "Level1.hpp"
#include "Level2.hpp"
using namespace Levels;

#include "GraphicManager.hpp"
#include "EventManager.hpp"
using namespace Managers;

#include "LevelMenu.hpp"
#include "PauseMenu.hpp"
using namespace Menus;

class Game
{
private:
    bool isRunning;

    GraphicManager *gfx;
    EventManager evManager;

    Player player;
    Player player2;
    Level1 lvl1;
    Level2 lvl2;
    LevelMenu menu;
    PauseMenu pause;

public:
    int gameState;

    Game();
    ~Game();

    void init();
    void update();
    void render();
    void clean();
};