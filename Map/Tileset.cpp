
#include "Tileset.hpp"

#include "Sprite.hpp"

Tileset::Tileset()
{
}

Tileset::Tileset(SDL_Renderer *renderer, std::string tilesetpath, int rows, int cols, int width, int height) : tilesetSprite(new Sprite()),
                                                                                       rowCount(rows),
                                                                                       colCount(cols),
                                                                                       tileWidth(width),
                                                                                       tileHeight(height)
{
    tilesetSprite->setProps(renderer, tilesetpath, width, height);
}

Tileset::~Tileset()
{
    delete tilesetSprite;
    tilesetSprite = nullptr;
}
