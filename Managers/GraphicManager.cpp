
#include "GraphicManager.hpp"
using namespace Managers;

#include <iostream>
using namespace std;

GraphicManager *GraphicManager::instance = nullptr;

GraphicManager::GraphicManager() : window(nullptr), renderer(nullptr)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Failed to Initialize SDL" << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow("Star Wars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, 0);
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

    sWidth = 1600;
    sHeight = 900;

    cout << "Graphic Manager Initialized " << endl;
}

GraphicManager::~GraphicManager()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    instance = nullptr;

    cout << "Graphic Manager Deleted" << endl;
}