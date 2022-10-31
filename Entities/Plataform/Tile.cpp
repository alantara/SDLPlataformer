
#include "Tile.hpp"

#include <iostream>

using namespace Entities;
using namespace Plataform;

Tile::Tile(SDL_Renderer* rend, int xpos, int ypos)
{
    x = xpos;
    y = ypos;
    active = true;
}

Tile::~Tile()
{
}

void Tile::update()
{
}