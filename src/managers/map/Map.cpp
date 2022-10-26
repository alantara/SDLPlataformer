
#include "Map.hpp"

#include <iostream>
#include <fstream>

#include "Core.hpp"
#include "Entity.hpp"
#include "Tiles.hpp"
#include "Sprite.hpp"
#include "EntityM.hpp"


Map::Map()
{

}

Map::Map(std::string mappath, Tileset* ts) :
tileset(ts)
{
    std::ifstream data(mappath, std::ios::in);

    if(!data)
    {
        std::cout << "Unable to open file" << std::endl;
        fflush ( stdin );
        getchar( );
    }

    data >> rowCount >> colCount;    

    int pos = 0;

    while(!data.eof())
    {
        int ext;
        data >> ext;

        int yt = ext/tileset->GetTileSetColCount();
        int xt = ext - yt * tileset->GetTileSetColCount();

        int y = pos/colCount;
        int x = pos - y * colCount;

        Tiles* tile = new Tiles("tile", x, y);

        Sprite* spr = new Sprite(tileset->GetTileSetSprite()->GetTexture(), tileset->GetTileWidth(), tileset->GetTileHeight(), xt, yt, 8);
        tile->setSprite(spr);

        EntityM::GetInstance()->AddEntity(tile);

        pos++;
    }
    data.close();
}

Map::~Map()
{
    delete tileset;
    tileset = nullptr;
}
