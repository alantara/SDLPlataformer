#include "Game.hpp"

#include <iostream>
using namespace std;

Game::Game() : gfx(GraphicManager::getInstance()), lvl1(&evManager, &player, &player2), lvl2(&evManager, &player, &player2), isRunning(true), gameState(0), menu(&evManager, this), pause(&evManager, this)
{
    cout << "Game Initialized" << endl;

    init();

    while (isRunning)
    {
        evManager.listen(isRunning);
        update();
        render();
    }

    clean();
}

Game::~Game()
{
    cout << "Game Deleted" << endl;
}

void Game::init()
{
    player.setSprite("assets/solo.png", 0, 0, 64, 59, 1);
    player.setInputSystem(&evManager, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_SPACE, SDL_SCANCODE_Q);

    player2.setSprite("assets/chew.png", 0, 0, 44, 64, 1);
    player2.setInputSystem(&evManager, SDL_SCANCODE_J, SDL_SCANCODE_L, SDL_SCANCODE_I, SDL_SCANCODE_U);
}

void Game::update()
{
    if(evManager.getKeyDown(SDL_SCANCODE_ESCAPE) && (gameState == 1 || gameState == 2))
    {
        lvl1.save();
        gameState = -1;
    }
    switch (gameState)
    {
    case -1:
        pause.update();
        break;
    case 0:
        menu.update();
        break;
    case 1:
        lvl1.update();
        break;
    case 2:
        lvl2.update();
        break;
    default:
        isRunning = false;
        break;
    }
}

void Game::render()
{
    SDL_RenderClear(gfx->getRenderer());
    switch (gameState)
    {
    case -1:
        pause.render();
        break;
    case 0:
        menu.render();
        break;
    case 1:
        lvl1.render();
        break;
    case 2:
        lvl2.render();
        break;
    default:
        isRunning = false;
        break;
    }
    SDL_RenderPresent(gfx->getRenderer());
}

void Game::clean()
{
    GraphicManager::getInstance()->deleteInstance();
}