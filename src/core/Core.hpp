
#pragma once

#include <SDL2/SDL.h>
#include "../gfx/TextureManager.hpp"
#include "../map/Map.hpp"

class Core
{
    public:
        Core();
        ~Core();

        /*  Class Methods   */
        int Execute();

        bool Init();
        void Clean();

        void Update();
        void Render();
        void Events();

        /*  Getter Methods   */
        TextureManager* GetTextureManager() { return gfxManager; }
        SDL_Window* GetWindow() { return Window; }
        SDL_Renderer* GetRenderer() { return Renderer; }

    private:
        bool RunState;

        Map* GameMap;
        TextureManager* gfxManager;
        SDL_Window* Window;
        SDL_Renderer* Renderer;
};