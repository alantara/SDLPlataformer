#include "Engine.h"

#include "../graphics/TextureManager.h"
#include "../characters/Player.h"
#include "../timer/Timer.h"
#include "../map/MapParser.h"

Engine* Engine::s_Instance = nullptr;
Player* m_Player = nullptr;

Engine::Engine()
{
    SDL_Log("starting engine");

    m_RunState = false;
}

bool Engine::Init()
{
    //SDL Inicialization
    SDL_Log("initializing SDL");
    if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }
    SDL_Log("SDL initialized");

    //Create Window Display
    SDL_Log("creating window");
    s_Window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(s_Window == nullptr)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }
    SDL_Log("window created");

    //Create Renderer
    SDL_Log("creating renderer");
    s_Renderer = SDL_CreateRenderer(s_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(s_Renderer == nullptr)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }
    SDL_Log("renderer created");

    m_RunState = true;

    if(MapParser::GetInstance()->Load())
    {
        std::cout << "Failed to load map" << std::endl;
    }

    m_LevelMap = MapParser::GetInstance()->GetMap("level1");

    //Inicializations
    TextureManager::GetInstance()->Load("player", "assets/idle-sprite.png");
    TextureManager::GetInstance()->Load("tree", "assets/tree.png");
    m_Player = new Player(new Properties("player", 100, 100, 16, 16));
}

bool Engine::Clean()
{
    SDL_Log("starting cleanup");

    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(s_Renderer);
    SDL_DestroyWindow(s_Window);
    IMG_Quit();
    SDL_Quit();

    SDL_Log("engine cleaned");

}

void Engine::Quit()
{
    SDL_Log("event quit, exiting game loop");
    m_RunState = false;
}

void Engine::Update()
{
    m_Player->Update(Timer::GetInstance()->GetDeltaTime());
    m_LevelMap->Update();
}

void Engine::Render()
{
    SDL_RenderClear(s_Renderer);

    SDL_SetRenderDrawColor(s_Renderer, 255, 255, 255, 255);
    m_Player->Draw();
    m_LevelMap->Render();
    TextureManager::GetInstance()->Draw("tree", 200, 100, 360, 510);
    SDL_RenderPresent(s_Renderer);
}

void Engine::Events()
{
    EventHandler::GetInstance()->Listen();
}
