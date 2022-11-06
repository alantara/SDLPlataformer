#include "Game.hpp"

#include <iostream>
using namespace std;

Game::Game() : gfx("Plataformer", 1600, 900), player(&gfx), player2(&gfx), lvl1(&gfx, &evManager, &player, &player2), isRunning(true), gameState(0), menu(&gfx, &evManager)
{
    cout << "Game Initialized" << endl;

    init();

    while (isRunning)
    {
        evManager.listen(isRunning);
        update();
        render();
    }
}

Game::~Game()
{
    cout << "Game Deleted" << endl;
}

void Game::init()
{
    player.setSprite(&gfx, "assets/luke.png", 0, 0, 64, 64, 1);
    player.setInputSystem(&evManager, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_SPACE, SDL_SCANCODE_Q);

    player2.setSprite(&gfx, "assets/bobbafett.png", 0, 0, 64, 64, 1);
    player2.setInputSystem(&evManager, SDL_SCANCODE_J, SDL_SCANCODE_L, SDL_SCANCODE_I, SDL_SCANCODE_U);
}

void Game::update()
{
    switch (gameState)
    {
    case 0:
        menu.update();
        break;
    case 1:
        lvl1.update();
        break;
    default:
        exit(1);
        break;
    }
}

void Game::render()
{
    SDL_RenderClear(gfx.getRenderer());
    switch (gameState)
    {
    case 0:
        menu.render();
        break;
    case 1:
        lvl1.render();
        break;
    default:
        exit(1);
        break;
    }
    SDL_RenderPresent(gfx.getRenderer());
}