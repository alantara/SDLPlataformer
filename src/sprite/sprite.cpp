#include <sprite/sprite.hpp>

SDL_Texture* Sprite::LoadTexture(Core Instance, const char* filePath)
{
    Sprite::texture = IMG_LoadTexture(Instance.renderer, filePath);

    if(Sprite::texture == NULL)
        return NULL;

    return Sprite::texture;
}

void RenderTexture(Core Instance, SDL_Texture* texture)
{
    SDL_RenderCopy(Instance.renderer, texture, NULL, NULL);
}