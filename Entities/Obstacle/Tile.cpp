
#include "Tile.hpp"

#include <iostream>

using namespace Entities;
using namespace Obstacles;

Tile::Tile(GraphicManager *graphM, int xpos, int ypos) : Obstacle(graphM)
{
    x = xpos;
    y = ypos;
}

Tile::~Tile()
{
}

void Tile::update()
{
}