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
#include "MainMenu.hpp"
#include "GameOver.hpp"
#include "Leaderboard.hpp"
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

    MainMenu mainMenu;
    LevelMenu menu;
    PauseMenu pause;
    GameOver over;
    Leaderboard ld;

public:
    Game();
    ~Game();

    void setMultiplayer(bool b) { multiplayer = b; }
    bool getMultiplayer() { return multiplayer; }

    int getGameState() { return gameState; }
    void setGameState(int g) { gameState = g; }

    void resetLevels();
    void Level1Initialize();
    void Level2Initialize();
    void saveLevel1();
    void saveLevel2();
    int loadLVL();
    void upLeaderboard();

    void init();
    void update();
    void render();
};