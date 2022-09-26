
#include "TextureManager.hpp"

#include <iostream>
#include "../core/Core.hpp"

TextureManager* TextureManager::Instance = nullptr;

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}



int TextureManager::Load(std::string id, std::string filepath)
{
    SDL_Texture *texture = IMG_LoadTexture(Core::GetInstance()->GetRenderer(), filepath.c_str());
	if (texture == nullptr){
        std::cout << "Texture could not be loaded" << std::endl;
		return 0;
	}

    TextureMap[id] = texture;

	return 1;
}

void TextureManager::Drop(std::string id)
{
    SDL_DestroyTexture(TextureMap[id]);
    TextureMap.erase(id);
}

void TextureManager::Clean()
{
    std::map<std::string, SDL_Texture*>::iterator it;
    for(it = TextureMap.begin(); it != TextureMap.end(); it++)
        SDL_DestroyTexture(it->second);
    TextureMap.clear();
}

void TextureManager::DrawTile(std::string id, int tileSize, int dst_multiplier, int row, int col, int x, int y)
{
    SDL_Rect srcRect = {tileSize * col, tileSize * row, tileSize, tileSize};

    int dstTilesize = tileSize * dst_multiplier;
    SDL_Rect dstRect = {x * dstTilesize, y * dstTilesize, dstTilesize, dstTilesize};
    SDL_RenderCopy(Core::GetInstance()->GetRenderer(), TextureMap[id], &srcRect, &dstRect);
}