
#include "Tileset.hpp"

#include "Sprite.hpp"

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
    tilesetSprite.setProps(renderer, tilesetpath, width, height);
}