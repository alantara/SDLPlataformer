#include "Level.hpp"

#include <iostream>
using namespace Levels;

Level::Level()
{
}

Level::~Level()
{
}

void Level::render(SDL_Renderer *renderer)
{
    entities.renderAll(renderer);
}