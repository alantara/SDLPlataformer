#include "Sprite.hpp"

using namespace Components;

Sprite::Sprite() : path(""), row(0), column(0), width(0), height(0), multiplier(1), texture(nullptr)
{

}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
    texture = nullptr;
}

void Sprite::setSprite(GraphicManager *gfxM, string p, int c, int r, int w, int h, int m)
{
    setPath(p);
    setTexture(gfxM, p);

    setRow(r);
    setColumn(c);
    setWidth(w);
    setHeight(h);
    setMultiplier(m);
}

void Sprite::setTexture(GraphicManager *gfxM, string p)
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    }

    SDL_Texture *tx = IMG_LoadTexture(gfxM->getRenderer(), p.c_str());
    if (tx == nullptr)
    {
        std::cout << "Texture could not be loaded: " << SDL_GetError() << std::endl;
        return;
    }

    texture = tx;
}

void Sprite::render(GraphicManager *gfxM, int x, int y)
{
    SDL_Rect srcRect = {column * width, row * height, width, height};
    SDL_Rect dstRect = {x, y, width * multiplier, height * multiplier};

    SDL_RenderCopy(gfxM->getRenderer(), texture, &srcRect, &dstRect);
}