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
    ~Map();

    void addTileset(SDL_Renderer *renderer, std::string tilesetpath, int rows, int cols, int width, int height);
    void init(SDL_Renderer *renderer, std::string mappath);

private:
    Tileset tileset;
    int rowCount, colCount;
};