#pragma once

#include <SDL2/SDL_ttf.h>
#include <string>
using namespace std;

#include "Player.hpp"
using namespace Entities;
using namespace Characters;

#include "GraphicManager.hpp"

class Font
{
private:
    TTF_Font *ST;
    SDL_Color Yellow;
    SDL_Surface *surfaceMessage;
    SDL_Texture *Message;
    SDL_Rect Message_rect;

public:
    Font(int x, int y, int w = 180, int h = 75)
    {
        TTF_Init();
        ST = TTF_OpenFont("assets/STJEDISE.TTF", 24);
        Yellow = {255, 191, 0};
        surfaceMessage = TTF_RenderText_Solid(ST, "", Yellow);
        Message = SDL_CreateTextureFromSurface(GraphicManager::getInstance()->getRenderer(), surfaceMessage);

        Message_rect.x = x;
        Message_rect.y = y;
        Message_rect.w = w;
        Message_rect.h = h;
    }
    ~Font()
    {
    }

    void setRect(int x, int y, int w, int h)
    {
        Message_rect.x = x;
        Message_rect.y = y;
        Message_rect.w = w;
        Message_rect.h = h;
    }

    void setMessage(string s)
    {
        surfaceMessage = TTF_RenderText_Solid(ST, s.c_str(), Yellow);
        Message = SDL_CreateTextureFromSurface(GraphicManager::getInstance()->getRenderer(), surfaceMessage);
    }

    void clean()
    {
        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(Message);
    }

    void render()
    {
        SDL_RenderCopy(GraphicManager::getInstance()->getRenderer(), Message, NULL, &Message_rect);
    }

    void update(string s)
    {
        clean();
        surfaceMessage = TTF_RenderText_Solid(ST, s.c_str(), Yellow);
        Message = SDL_CreateTextureFromSurface(GraphicManager::getInstance()->getRenderer(), surfaceMessage);
    }
};