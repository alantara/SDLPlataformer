#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <string>

#include "Tileset.hpp"
#include "EntityList.hpp"
using namespace Lists;

class Map
{
public:
    Map();
    Map(SDL_Renderer *renderer, std::string mappath, Tileset *ts);
    ~Map();

private:
    Tileset *tileset;
    int rowCount, colCount;
};