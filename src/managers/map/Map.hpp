
#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <string>

#include "Tileset.hpp"

class Map
{
    public:
        Map();
        Map(std::string mappath, Tileset* ts);
        ~Map();

    private:

        Tileset* tileset;
        int rowCount, colCount;
};