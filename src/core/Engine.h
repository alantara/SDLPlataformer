#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

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

        SDL_Window* s_Window;
        SDL_Renderer* s_Renderer;
};

#endif // ENGINE_H
