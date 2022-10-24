
#include "Screen.hpp"

#include <iostream>


Screen* Screen::Instance = nullptr;

/*  Constructor and Destructor  */
Screen::Screen()
{
    screenWindow = nullptr;
    screenRenderer = nullptr;
}

Screen::~Screen()
{

}


/*  Initialization and Clean    */
bool Screen::Init(std::string title, int w, int h, Uint32 flags)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Failed to Initialize SDL" << std::endl;
        return false;
    }

    screenWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
    if(screenWindow == nullptr)
    {
        std::cout << "Failed to Initialize Window" << std::endl;
        return false;
    }

    screenRenderer = SDL_CreateRenderer(screenWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    if(screenRenderer == nullptr)
    {
        std::cout << "Failed to Initialize Renderer" << std::endl;
        return false;
    }

    return true;
}

void Screen::Clean()
{    
    SDL_DestroyWindow(screenWindow);
    SDL_DestroyRenderer(screenRenderer);
    SDL_Quit();
}




/*  Logic Functions */
void Screen::RenderPrepare()
{
    SDL_RenderClear(screenRenderer);

    SDL_SetRenderDrawColor(screenRenderer, 255, 255, 255, 255);
}

void Screen::RenderPresent()
{
    SDL_RenderPresent(screenRenderer);
}