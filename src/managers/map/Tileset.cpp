
#include "Tileset.hpp"

#include "Sprite.hpp"

Tileset::Tileset()
{
    
}

Tileset::Tileset(std::string tilesetpath, int rows, int cols, int width, int height) :
tilesetSprite(new Sprite(tilesetpath, width, height)),
rowCount(rows),
colCount(cols),
tileWidth(width),
tileHeight(height)
{

}

Tileset::~Tileset()
{
    delete tilesetSprite;
    tilesetSprite = nullptr;
}
