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
}

Level::~Level()
{
    cout << "Level Destroyed" << endl;
}

void Level::render()
{
    entList.renderAll();
}