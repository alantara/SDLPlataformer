#include "Game.hpp"


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

    lvl1.getMap()->setTilesetProps(gfx.getRenderer(), "assets/texture.png", 22, 24, 8, 8);
    lvl1.getMap()->init(gfx.getRenderer(), "assets/data.dat", lvl1.getEntityList());

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

    lvl1.render();

    SDL_SetRenderDrawColor(gfx.getRenderer(), 0, 0, 255, 255);
    SDL_RenderPresent(gfx.getRenderer());
}