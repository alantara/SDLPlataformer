#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <string>

#include "EntityList.hpp"
using namespace Lists;

class Map
{
public:
    Map();
    ~Map();

    void init(SDL_Renderer *renderer, std::string mappath, EntityList *entities);

private:
    int rowCount, colCount;
};