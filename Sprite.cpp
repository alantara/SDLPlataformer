#include "Sprite.hpp"
#include <iostream>
#include "GraphicManager.hpp"

using namespace std;

Sprite::Sprite(SDL_Renderer *renderer, std::string filepath, int width, int height, int row, int col, int mult)
{
    spriteTexture = nullptr;

    srcRow = row;
    srcCol = col;
    srcWidth = width;
    srcHeight = height;
    multiplier = mult;

    SDL_Texture *texture = IMG_LoadTexture(renderer, filepath.c_str());
    if (texture == nullptr)
    {
        std::cout << "Texture could not be loaded: " << SDL_GetError() << std::endl;
        return;
    }

    spriteTexture = texture;
}

Sprite::~Sprite()
{
    cout << "Destroy" << endl;

    SDL_DestroyTexture(spriteTexture);
    spriteTexture = nullptr;
}

void Sprite::renderObstacle(SDL_Renderer *renderer, int x, int y)
{
    SDL_Rect srcRect = {srcCol * srcWidth, srcRow * srcHeight, srcWidth, srcHeight};
    SDL_Rect dstRect = {x * srcWidth * multiplier, y * srcHeight * multiplier, srcWidth * multiplier, srcHeight * multiplier};

    SDL_RenderCopy(renderer, spriteTexture, &srcRect, &dstRect);
}

void Sprite::renderCharacters(SDL_Renderer *renderer, int x, int y)
{
    SDL_Rect srcRect = {srcCol * srcWidth, srcRow * srcHeight, srcWidth, srcHeight};
    SDL_Rect dstRect = {x, y, srcWidth * multiplier, srcHeight * multiplier};

    SDL_RenderCopy(renderer, spriteTexture, &srcRect, &dstRect);
}