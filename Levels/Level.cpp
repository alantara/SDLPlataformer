#include "Level.hpp"

#include <iostream>
using namespace std;
using namespace Levels;

#include "Tile.hpp"
using namespace Entities;
using namespace Obstacles;

Level::Level(GraphicManager *graphM) : Ente(graphM)
{
    cout << "Level Initialized " << endl;

    Tile *tile = new Tile(graphM, 500, 500);
    Tile *tile2 = new Tile(graphM, 200, 200);
    Tile *tile3 = new Tile(graphM, 0, 0);

    entList.insert(static_cast<Entity *>(tile));
    entList.insert(static_cast<Entity *>(tile2));
    entList.insert(static_cast<Entity *>(tile3));
}

Level::~Level()
{
    cout << "Level Destroyed" << endl;
}

void Level::render()
{
    entList.renderAll();
}