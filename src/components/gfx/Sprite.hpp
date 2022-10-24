
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Sprite
{
    public:

        Sprite();
        ~Sprite();

        /*  Class Methods   */
        bool LoadTexture(std::string filepath);
        void DropTexture();

        void Render(int x, int y, int dst_multiplier = 1);

    private:

        SDL_Texture* spriteTexture;
        int srcRow, srcCol, srcW, srcH;
};