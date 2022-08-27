#include "TextureManager.h"

#include "Engine.h"

TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::Load(std::string id, std::string filename)
{
    //Load image
    SDL_Log("loading image. id: %s", id.c_str());///Log
    SDL_Surface* m_Surface = IMG_Load(filename.c_str());
    if(m_Surface == nullptr)
    {
        SDL_Log("Failed to load texture: %s, %s", filename.c_str(), SDL_GetError());
        return false;
    }
    SDL_Log("image loaded. id: %s", id.c_str());

    //Create Texture from image
    SDL_Log("creating texture. id: %s", id.c_str());///Log
    SDL_Texture* m_Texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), m_Surface);
    if(m_Texture == nullptr)
    {
        SDL_Log("Failed to create texture from surface: %s, %s", filename.c_str(), SDL_GetError());
        return false;
    }
    SDL_Log("texture created. id: %s", id.c_str());///Log

    m_TextureMap[id] = m_Texture;
    return true;
}

void TextureManager::Drop(std::string id)
{
    SDL_Log("destroying texture. id: %s", id.c_str());///Log

    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);

    SDL_Log("texture destroyed. id: %s", id.c_str());///Log
}

void TextureManager::Clean()
{
    SDL_Log("cleaning texture map");///Log
    std::map<std::string, SDL_Texture*>::iterator it;
    for(it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
        SDL_DestroyTexture(it->second);
    m_TextureMap.clear();
    SDL_Log("texture map cleaned");///Log

}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {width * frame, height * row, width, height};
    SDL_Rect dstRect = {x, y, width * 4, height * 4};
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}
