#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <core/core.cpp>

class Sprite
{
    public:
        SDL_Texture* texture;
        SDL_Texture* LoadTexture(Core Instance, const char* filePath);
        void RenderTexture(Core Instance, SDL_Texture* texture);
};
