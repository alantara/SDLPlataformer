#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Sprite
{
    public:
        Sprite(SDL_Renderer *renderer, std::string filepath, int width, int height, int row, int col, int mult);
        ~Sprite();

        void render(SDL_Renderer *renderer, int x, int y);

        SDL_Texture *getTexture() const { return spriteTexture; }
        int getRow() const { return srcRow; }
        int getWidth() const { return srcWidth; }
        int getHeight() const { return srcHeight; }

    private:

        SDL_Texture *spriteTexture;
        int srcRow, srcCol, srcWidth, srcHeight;
        int multiplier;
};