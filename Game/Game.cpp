#include "Game.hpp"

#include <iostream>
using namespace std;

Game::Game() : gfx("Plataformer", 1600, 900),
               player(&gfx),
               player2(&gfx),
               lvl1(&gfx, &evManager, &player, &player2),
               isRunning(true)

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
    player.setInputSystem(&evManager, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_SPACE);
    
    player2.setSprite(&gfx, "assets/bobbafett.png", 0, 0, 64, 64, 1);
    player2.setInputSystem(&evManager, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_UP);
}

void Game::update()
{
    lvl1.update();
}

void Game::render()
{
    SDL_RenderClear(gfx.getRenderer());

    lvl1.render();

    SDL_RenderPresent(gfx.getRenderer());
}