
#include "GraphicManager.hpp"

#include <iostream>

GraphicManager::GraphicManager()
{
    window = nullptr;
    renderer = nullptr;
}

GraphicManager::~GraphicManager()
{
}

bool GraphicManager::init(std::string title, int width, int height, Uint32 flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Failed to Initialize SDL" << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    if (window == nullptr)
    {
        std::cout << "Failed to Initialize Window" << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        std::cout << "Failed to Initialize Renderer" << std::endl;
        return false;
    }

    width = width;
    height = height;

    return true;
}

void GraphicManager::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}