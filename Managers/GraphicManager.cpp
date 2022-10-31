
#include "GraphicManager.hpp"

#include <iostream>
using namespace std;

GraphicManager::GraphicManager(std::string title, int width, int height, Uint32 flags) :
window(nullptr), renderer(nullptr)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Failed to Initialize SDL" << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    if (window == nullptr)
    {
        std::cout << "Failed to Initialize Window" << std::endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        std::cout << "Failed to Initialize Renderer" << std::endl;
        exit(1);
    }

    width = width;
    height = height;

    cout << "Graphic Manager Initialized" << endl;
}

GraphicManager::~GraphicManager()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    cout << "Graphic Manager Deleted" << endl;
}