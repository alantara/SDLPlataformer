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
    SDL_Color White;
    SDL_Surface *surfaceMessage;
    SDL_Texture *Message;
    SDL_Rect Message_rect;

public:
    Font()
    {
        TTF_Init();
        ST = TTF_OpenFont("assets/STJEDISE.TTF", 24);
        White = {255, 255, 255};
        surfaceMessage = TTF_RenderText_Solid(ST, "0", White);
        Message = SDL_CreateTextureFromSurface(GraphicManager::getInstance()->getRenderer(), surfaceMessage);

        Message_rect.x = 910;
        Message_rect.y = 30;
        Message_rect.w = 100;
        Message_rect.h = 100;
    }
    ~Font()
    {
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

    void update()
    {
        clean();
        surfaceMessage = TTF_RenderText_Solid(ST, to_string(Player::getScorePoints()).c_str(), White);
        Message = SDL_CreateTextureFromSurface(GraphicManager::getInstance()->getRenderer(), surfaceMessage);
    }
};