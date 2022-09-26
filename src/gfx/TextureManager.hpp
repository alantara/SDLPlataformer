
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

class TextureManager
{
    public:

        /*  Class Methods   */
        int Load(std::string id, std::string filepath);
        void Drop(std::string id);
        void Clean();

        void DrawTile(std::string id, int tileSize, int dst_multiplier, int row, int col, int x, int y);

        /*  Getter Methods  */
        std::map<std::string, SDL_Texture*> GetTextureMap() { return TextureMap; }

        /*  Instance    */
        static TextureManager* GetInstance()
        {
            return Instance = Instance ? Instance : new TextureManager();
        }

    private:
        TextureManager();
        ~TextureManager();

        std::map<std::string, SDL_Texture* > TextureMap;

        static TextureManager* Instance;
};