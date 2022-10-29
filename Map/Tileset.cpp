
#include "Tileset.hpp"

#include "Sprite.hpp"
#include <iostream>

Tileset::Tileset()
{
}

Tileset::~Tileset()
{
}

void Tileset::setProps(SDL_Renderer *renderer, std::string tilesetpath, int rows, int cols, int width, int height)
{
    rowCount = rows;
    colCount = cols;
    tileWidth = width;
    tileHeight = height;
    std::cout << colCount << std::endl;

    tilesetSprite.setProps(renderer, tilesetpath, width * cols, height * rows);
}