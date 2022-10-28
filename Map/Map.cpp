
#include "Map.hpp"

#include <iostream>
#include <fstream>

#include "Entity.hpp"
#include "Sprite.hpp"
#include "Tile.hpp"
using namespace Entities;
using namespace Plataform;

Map::Map()
{
}

Map::Map(SDL_Renderer *renderer, std::string mappath, Tileset *ts) : tileset(ts)
{
    std::ifstream data(mappath, std::ios::in);

    if (!data)
    {
        std::cout << "Unable to open file" << std::endl;
        fflush(stdin);
        getchar();
    }

    data >> rowCount >> colCount;

    int pos = 0;

    while (!data.eof())
    {
        int ext;
        data >> ext;

        int yt = ext / tileset->getTileSetColCount();
        int xt = ext - yt * tileset->getTileSetColCount();

        int y = pos / colCount;
        int x = pos - y * colCount;

        Tile *tile = new Tile(x, y);

        tile->getSprite().setProps(renderer, tileset->getTileSetSprite()->getTexture(), tileset->getTileWidth(), tileset->getTileHeight(), xt, yt, 8);

        pos++;
    }
    data.close();
}

Map::~Map()
{
    delete tileset;
    tileset = nullptr;
}
