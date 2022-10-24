
#include "Sprite.hpp"

#include <iostream>
#include "Core.hpp"
#include "Screen.hpp"


Sprite::Sprite()
{
    spriteTexture = nullptr;
}

Sprite::~Sprite()
{

}



bool Sprite::LoadTexture(std::string filepath)
{
    SDL_Texture *texture = IMG_LoadTexture(Screen::GetInstance()->GetRenderer(), filepath.c_str());
	if (texture == nullptr){
        std::cout << "Texture could not be loaded" << std::endl;
		return false;
	}

    spriteTexture = texture;

	return true;
}

void Sprite::DropTexture()
{
    SDL_DestroyTexture(spriteTexture);
}

void Sprite::Render(int x, int y, int dst_multiplier)
{
    SDL_Rect srcRect = {srcCol * srcW, srcRow * srcH, srcW, srcH};
    SDL_Rect dstRect = {x * srcW * dst_multiplier, y * srcH * dst_multiplier, srcW * dst_multiplier, srcH * dst_multiplier};

    SDL_RenderCopy(Screen::GetInstance()->GetRenderer(), texture, &srcRect, &dstRect);
}