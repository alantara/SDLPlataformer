
#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "../gfx/TextureManager.hpp"

class Map
{
    public:

        /*  Class Methods   */
        void Render();
        void LiveRender();

        /*  Instance    */
        static Map* GetInstance()
        {
            return Instance = Instance ? Instance : new Map();
        }

    private:
        Map();
        ~Map();

        int mapRows, mapCols;
        int tilemapRows, tilemapCols, tileSize, tileMultiplier;
        int displayedTileSize;

        int** GameMap;
        std::vector<std::vector<int>> CollisionMap();
        
        static Map* Instance;
};