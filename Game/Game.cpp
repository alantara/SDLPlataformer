#include "Game.hpp"

#include <iostream>
using namespace std;

Game::Game(): 
gfx("Plataformer", 800, 800),
events(),
lvl1(&gfx)
{
    cout << "Game Initialized" << gfx.getHeight() << endl;

    isRunning = true;

    while (isRunning)
    {
        events.listen(isRunning);
        SDL_RenderClear(gfx.getRenderer());
        
        update();
        render();

        SDL_RenderPresent(gfx.getRenderer());
    }
}

Game::~Game()
{
    cout << "Game Deleted" << endl;
}

void Game::update()
{

}

void Game::render()
{
    lvl1.render(gfx.getRenderer());
}