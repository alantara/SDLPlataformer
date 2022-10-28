#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Sprite
{
    public:

        Sprite();
        ~Sprite();

        void render(SDL_Renderer *renderer, int x, int y);

        SDL_Texture *getTexture() const { return spriteTexture; }
        void setProps(SDL_Renderer *renderer, std::string filepath, int width, int height, int row = 0, int col = 0, int multiplier = 1);
        void setProps(SDL_Renderer *renderer, SDL_Texture *tx, int width, int height, int row = 0, int col = 0, int multiplier = 1);

        void setMultiplier(int mult) { multiplier = mult; }

    private:

        SDL_Texture *spriteTexture;
        int srcRow, srcCol, srcWidth, srcHeight;
        int multiplier;
};