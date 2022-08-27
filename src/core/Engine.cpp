#include "Engine.h"

#include <SDL.h>
#include "TextureManager.h"
#include "Player.h"
#include "EventHandler.h"
#include "Timer.h"

Engine* Engine::s_Instance = nullptr;
Player* m_Player = nullptr;

Engine::Engine()
{
    SDL_Log("starting engine");///Log
    m_RunState = false;
}

bool Engine::Init()
{
    //SDL Inicialization
    SDL_Log("initializing SDL");///Log
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());///Log
        return false;
    }
    SDL_Log("SDL initialized");///Log

    //Create Window Display
    SDL_Log("creating window");///Log
    s_Window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(s_Window == nullptr)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());///Log
        return false;
    }
    SDL_Log("window created");///Log

    //Create Renderer
    SDL_Log("creating renderer");///Log
    s_Renderer = SDL_CreateRenderer(s_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(s_Renderer == nullptr)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());///Log
        return false;
    }
    SDL_Log("renderer created");///Log

    m_RunState = true;

    //Inicializations
    TextureManager::GetInstance()->Load("player", "assets/idle-sprite.png");
    TextureManager::GetInstance()->Load("tree", "assets/tree.png");
    m_Player = new Player(new Properties("player", 100, 100, 16, 16));
}

bool Engine::Clean()
{
    SDL_Log("starting cleanup");///Log

    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(s_Renderer);
    SDL_DestroyWindow(s_Window);
    IMG_Quit();
    SDL_Quit();

    SDL_Log("engine cleaned");///Log

}

void Engine::Quit()
{
    SDL_Log("event quit, exiting game loop");///Log
    m_RunState = false;
}

void Engine::Update()
{
    m_Player->Update(Timer::GetInstance()->GetDeltaTime());
}

void Engine::Render()
{
    SDL_RenderClear(s_Renderer);

    SDL_SetRenderDrawColor(s_Renderer, 255, 255, 255, 255);
    m_Player->Draw();
    TextureManager::GetInstance()->Draw("tree", 200, 100, 360, 510);
    SDL_RenderPresent(s_Renderer);
}

void Engine::Events()
{
    EventHandler::GetInstance()->Listen();
}
