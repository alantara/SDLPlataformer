
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Sprite
{
    public:

        Sprite();
        Sprite(std::string filepath, int width, int height, int row = 0, int col = 0, int multiplier = 1);
        Sprite(SDL_Texture* texture, int width, int height, int row = 0, int col = 0,  int multiplier = 1);
        ~Sprite();

        void Render(int x, int y);

        SDL_Texture* GetTexture() const { return spriteTexture; }

        void SetDSTMultiplier(int multiplier) { dst_multiplier = multiplier; }

    private:

        SDL_Texture* spriteTexture;
        int srcRow, srcCol, srcWidth, srcHeight;
        int dst_multiplier;
};