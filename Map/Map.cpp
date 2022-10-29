
#include "Map.hpp"

#include <iostream>
#include <fstream>

#include "Entity.hpp"
#include "Tile.hpp"
#include "EntityList.hpp"
using namespace Lists;
using namespace Entities;
using namespace Plataform;

Map::Map()
{
}

Map::~Map()
{
}

void Map::setTilesetProps(SDL_Renderer *renderer, std::string tilesetpath, int rows, int cols, int width, int height)
{
    tileset.setProps(renderer, tilesetpath, rows, cols, width, height);
}

void Map::init(SDL_Renderer *renderer, std::string mappath, EntityList* entities)
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

        int yt = ext / tileset.getTileSetColCount();
        int xt = ext - yt * tileset.getTileSetColCount();

        int y = pos / colCount;
        int x = pos - y * colCount;

        Tile tile(x, y);

        tile.getSprite().setProps(renderer, tileset.getTileSetSprite().getTexture(), tileset.getTileWidth(), tileset.getTileHeight(), xt, yt, 8);

        entities->insert(static_cast<Entity>(tile));

        pos++;
    }
    data.close();
}

