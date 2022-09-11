
#pragma once 

#include "Layer.h"
#include <vector>
#include <string>

struct Tileset
{
    int firstID, lastID;
    int rowCount, colCount;
    int tileCount, tileSize;
    std::string Name, source;
};

using TilesetList = std::vector<Tileset>;
using TileMap = std::vector<std::vector<int> >;

class TileLayer : public Layer
{
    public:
        TileLayer(int tilesize, int rowcount, int colcount, TileMap tilemap, TilesetList tilesets);
        virtual void Render();
        virtual void Update();
        inline TileMap GetTileMap() {return m_Tilemap;}

    private:
        int m_TileSize;
        int m_ColCount, m_RowCount;
        TileMap m_Tilemap;
        TilesetList m_Tilesets;
};