#include "Game.hpp"

#include "Tile.hpp"
using namespace Entities;
using namespace Plataform;

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

    Tile *tile = new Tile(0, 0);
    lvl1.getEntityList()->insert(static_cast<Entity *>(tile));
    Tile *tile2 = new Tile(1, 0);
    lvl1.getEntityList()->insert(static_cast<Entity *>(tile2));
    Tile *tile3 = new Tile(2, 0);
    lvl1.getEntityList()->insert(static_cast<Entity *>(tile3));
    std::cout << tile3 << std::endl;
    // lvl1.getMap()->setTilesetProps(gfx.getRenderer(), "assets/texture.png", 22, 24, 8, 8);
    // lvl1.getMap()->init(gfx.getRenderer(), "assets/data.dat", lvl1.getEntityList());

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