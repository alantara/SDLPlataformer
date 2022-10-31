#include "Level.hpp"

#include <iostream>
using namespace std;
using namespace Levels;

#include "Tile.hpp"
using namespace Entities;
using namespace Plataform;

Level::Level(GraphicManager *graphM) : 
Ente(graphM)
{
    cout << "Level Initialized "  << gfx->getHeight() << endl;

    Tile tile(0, 0);

    //entList.insert(static_cast<Entity>(tile));
}

Level::~Level()
{
    cout << "Level Initialized" << endl;
}

void Level::render(SDL_Renderer *renderer)
{
    entList.renderAll(renderer);
}