
#include "Core.hpp"

#include <iostream>
#include <fstream>

#define WINDOW_WIDTH 1600
#define WINNDOW_HEIGHT 900

Core::Core()
{
    GameMap = nullptr;
    Window = nullptr;
    Renderer = nullptr;
    RunState = true;
}

Core::~Core()
{

}

int Core::Execute()
{
    if(!Init())
    {
        return -1;
    }

    while(RunState)
    {
        Events();
        Update();
        Render();
    }

    Clean();

    return 0;
}

bool Core::Init()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Failed to Initialize SDL" << std::endl;
        return false;
    }

    Window = SDL_CreateWindow("Plataformer  ", 100, 100, WINDOW_WIDTH, WINNDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
    if(Window == nullptr)
    {
        std::cout << "Failed to Initialize Window" << std::endl;
        return false;
    }

    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_PRESENTVSYNC);
    if(Renderer == nullptr)
    {
        std::cout << "Failed to Initialize Renderer" << std::endl;
        return false;
    }

    gfxManager = new TextureManager();
    gfxManager->Load(Renderer, "das", "texture.png");

    GameMap = new Map();

    return true;
}

void Core::Update()
{

}

void Core::Render()
{
    SDL_RenderClear(Renderer);

    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);

    GameMap->Render(Renderer, gfxManager);

    SDL_RenderPresent(Renderer);
}

void Core::Events()
{
    SDL_Event Event;

    while(SDL_PollEvent(&Event))
    {
        if(Event.type == SDL_QUIT)
        {
            RunState = false;
        }
    }
    
}

void Core::Clean()
{
    gfxManager->Clean();
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
}
