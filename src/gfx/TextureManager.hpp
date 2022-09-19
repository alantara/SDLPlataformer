
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

class TextureManager
{
    public:
        TextureManager(){}
        ~TextureManager();

        /*  Class Methods   */
        int Load(SDL_Renderer* renderer, std::string id, std::string filepath);
        void Drop(std::string id);
        void Clean();

        void DrawTile(SDL_Renderer* renderer, std::string id, int tileSize, int dst_multiplier, int row, int col, int x, int y);

        std::map<std::string, SDL_Texture*> GetTextureMap() { return TextureMap; }
        std::map<std::string, SDL_Texture* > TextureMap;
    private:

};