
#include "Map.hpp"

#include <fstream>

Map::Map()
{

}

Map::~Map()
{

}

void Map::Render(SDL_Renderer* renderer, TextureManager* gfxManager)
{
    std::ifstream data("data.dat", std::ios::in);

    if(!data)
    {
        std::cerr << " Arquivo não pode ser aberto " << std::endl;
        fflush ( stdin );
        getchar( );
    }

    int tilemapRows, tilemapCols;
    data >> tilemapRows >> tilemapCols;

    int mapRows, mapCols, pos = 0;
    data >> mapRows >> mapCols;

    while(!data.eof())
    {
        int ext;
        data >> ext;

        int row = ext/tilemapCols;        
        int col = ext - row * tilemapCols;

        int y = pos/mapCols;
        int x = pos - y * mapCols;

        gfxManager->DrawTile(renderer, "das", 8, 8, row, col, x, y);
        pos++;
    }
    data.close();
}
