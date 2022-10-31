#include "Game.hpp"

#include <iostream>
using namespace std;

Game::Game() : gfx("Plataformer", 1600, 900),
               events(),
               lvl1(&gfx)
{
    cout << "Game Initialized" << endl;
    player = new Player(&gfx, &events, 0, 0);
    lvl1.getEntityList()->insert(static_cast<Entity *>(player));

    isRunning = true;

    while (isRunning)
    {
        events.listen(isRunning);

        update();
        render();
    }
}

Game::~Game()
{
    cout << "Game Deleted" << endl;
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