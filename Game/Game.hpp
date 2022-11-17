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
    bool multiplayer;
    int gameState;

    static GraphicManager *gfx;
    EventManager evManager;

    Player *player;
    Player *player2;
    Level1 lvl1;
    Level2 lvl2;
    LevelMenu menu;
    PauseMenu pause;

public:
    Game();
    ~Game();

    int getGameState() { return gameState; }
    void setGameState(int g) { gameState = g; }

    void resetLevels();

    void init();
    void update();
    void render();
};