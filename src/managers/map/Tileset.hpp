
#pragma once

#include <map>
#include <string>
#include "Sprite.hpp"

class Tileset
{
    public:

        Tileset();
        Tileset(std::string tilesetpath, int rows, int cols, int width, int height);
        ~Tileset();

        void setTileSetRowCount(int row) { rowCount = row; }
        void setTileSetColCount(int col) { colCount = col; }


        Sprite* GetTileSetSprite() const { return tilesetSprite; }
        int GetTileSetRowCount() const { return rowCount; }
        int GetTileSetColCount() const { return colCount; }
        int GetTileWidth() const { return tileWidth; }
        int GetTileHeight() const { return tileHeight; }

    private:
        
        Sprite* tilesetSprite;

        int rowCount, colCount;
        int tileWidth, tileHeight;
};