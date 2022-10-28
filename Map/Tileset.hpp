
#pragma once

#include <map>
#include <string>
#include "Sprite.hpp"

class Tileset
{
public:
    Tileset();
    Tileset(SDL_Renderer *renderer, std::string tilesetpath, int rows, int cols, int width, int height);
    ~Tileset();

    Sprite *getTileSetSprite() const { return tilesetSprite; }
    int getTileSetRowCount() const { return rowCount; }
    int getTileSetColCount() const { return colCount; }
    int getTileWidth() const { return tileWidth; }
    int getTileHeight() const { return tileHeight; }

private:
    Sprite *tilesetSprite;

    int rowCount, colCount;
    int tileWidth, tileHeight;
};