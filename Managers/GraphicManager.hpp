
#pragma once

#include <SDL2/SDL.h>
#include <string>
namespace Managers
{
    class GraphicManager
    {
    public:
        GraphicManager(std::string title, int width = 1600, int height = 900, Uint32 flags = 0);
        ~GraphicManager();

        SDL_Window *getWindow() const { return window; }
        SDL_Renderer *getRenderer() const { return renderer; }
        int getWidth() const { return sWidth; }
        int getHeight() const { return sHeight; }

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        int sWidth, sHeight;
    };
}