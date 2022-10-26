
#include "Sprite.hpp"

#include <iostream>
#include "Screen.hpp"

Sprite::Sprite()
{

}

Sprite::Sprite(std::string filepath, int width, int height, int row, int col, int multiplier) :
spriteTexture(nullptr),
srcRow(row),
srcCol(col),
srcWidth(width),
srcHeight(height),
dst_multiplier(multiplier)
{
    SDL_Texture *texture = IMG_LoadTexture(Screen::GetInstance()->GetRenderer(), filepath.c_str());
	if (texture == nullptr){
        
        std::cout << "Texture could not be loaded" << SDL_GetError() << std::endl;
		return;
	}

    spriteTexture = texture;
}

Sprite::Sprite(SDL_Texture* texture, int width, int height, int row, int col, int multiplier) :
spriteTexture(texture),
srcRow(row),
srcCol(col),
srcWidth(width),
srcHeight(height),
dst_multiplier(multiplier)
{
    
}


Sprite::~Sprite()
{
    SDL_DestroyTexture(spriteTexture);
    spriteTexture = nullptr;
}

void Sprite::Render(int x, int y)
{
    SDL_Rect srcRect = {srcCol * srcWidth, srcRow * srcHeight, srcWidth, srcHeight};
    SDL_Rect dstRect = {x * srcWidth * dst_multiplier, y * srcHeight * dst_multiplier, srcWidth * dst_multiplier, srcHeight * dst_multiplier};

    SDL_RenderCopy(Screen::GetInstance()->GetRenderer(), spriteTexture, &srcRect, &dstRect);
}