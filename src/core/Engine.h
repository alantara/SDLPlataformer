
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../event-handler/EventHandler.h"
#include "../map/GameMap.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

class Engine
{
    public:
        static Engine* GetInstance()
        {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
        }

        bool Init();
        bool Clean();
        void Quit();

        void Update();
        void Render();
        void Events();

        inline bool IsRunning()
        {
            return m_RunState;
        }
        inline SDL_Renderer* GetRenderer()
        {
            return s_Renderer;
        }

    private:
        Engine();
        static Engine* s_Instance;
        bool m_RunState;

        GameMap* m_LevelMap;
        SDL_Window* s_Window;
        SDL_Renderer* s_Renderer;
};