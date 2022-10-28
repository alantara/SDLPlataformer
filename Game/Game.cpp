#include "Game.hpp"
#include "GraphicManager.hpp"
#include "Tileset.hpp"

Game::Game()
{
    isRunning = true;
}

Game::~Game()
{

}


void Game::init()
{
    gfx.init("Plataformer", 800, 600);
    isRunning = true;

    Tileset *ts = new Tileset(gfx.getRenderer(), "assets/texture.png", 22, 24, 8, 8);
    Map *map = new Map(gfx.getRenderer(), "assets/data.dat", ts);

    run();
}
void Game::run()
{
    SDL_Event outputEvent;

    while (isRunning)
    {
        isRunning = events.listen();

        update();
        render();
    }
}
void Game::update()
{
    
}
void Game::render()
{
    SDL_RenderClear(gfx.getRenderer());

    SDL_SetRenderDrawColor(gfx.getRenderer(), 0, 0, 255, 255);
    SDL_RenderPresent(gfx.getRenderer());
}