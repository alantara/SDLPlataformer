
#include "Map.hpp"

#include <iostream>
#include <fstream>
#include "../../core/Core.hpp"

Map* Map::Instance = nullptr;

Map::Map()
{
    std::ifstream data("assets/data.dat", std::ios::in);

    if(!data)
    {
        std::cout << "Unable to open file" << std::endl;
        fflush ( stdin );
        getchar( );
    }

    data >> tilemapRows >> tilemapCols;

    data >> mapRows >> mapCols;

    GameMap = (int**) malloc(sizeof(int*) * mapRows);
    for(int i = 0; i < mapRows; i++)
    {
        GameMap[i] = (int*) malloc (sizeof(int) * mapCols);
    }

    int pos = 0;

    while(!data.eof())
    {
        int ext;
        data >> ext;

        int y = pos/mapCols;
        int x = pos - y * mapCols;

        GameMap[y][x] = ext;
        pos++;
    }
    data.close();
}

Map::~Map()
{

}

void Map::Render()
{

    int elem;
    
    for(int i = 0; i < mapRows; i++)
    {
        for(int j = 0; j < mapCols; j++)
        {
            elem = GameMap[i][j];

            int row = elem/tilemapCols;        
            int col = elem - row * tilemapCols;

            TextureManager::GetInstance()->DrawTile("das", 8, 4, row, col, j, i);
        }
    }
    
}

void Map::LiveRender()
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

        TextureManager::GetInstance()->DrawTile("das", 8, 4, row, col, x, y);
        pos++;
    }
    data.close();
}