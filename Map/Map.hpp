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

    void setTilesetProps(SDL_Renderer *renderer, std::string tilesetpath, int rows, int cols, int width, int height);
    void init(SDL_Renderer *renderer, std::string mappath, EntityList *entities);

    Tileset getTileset() { return tileset; }

private:
    Tileset tileset;
    int rowCount, colCount;
};