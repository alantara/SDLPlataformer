
#pragma once

#include <SDL2/SDL.h>

class Core
{
    public:

        /*  Class Methods   */
        int Execute();

        bool Init();
        void Clean();

        void Update();
        void Render();
        void Events();

        /*  Getter Methods   */
        SDL_Window* GetWindow() { return Window; }
        SDL_Renderer* GetRenderer() { return Renderer; }

        /*  Instance    */
        static Core* GetInstance()
        {
            return Instance = Instance ? Instance : new Core();
        }
        
    private:
        Core();
        ~Core();
        bool RunState;

        SDL_Window* Window;
        SDL_Renderer* Renderer;

        static Core* Instance;
};