
#pragma once

#include <SDL2/SDL.h>
#include <string>
namespace Managers
{
    class GraphicManager
    {
    public:
        SDL_Window *getWindow() const { return window; }
        SDL_Renderer *getRenderer() const { return renderer; }
        static int getWidth() { return sWidth; }
        static int getHeight() { return sHeight; }

        static GraphicManager *getInstance() { return instance = (instance == nullptr) ? new GraphicManager() : instance; }
        void deleteInstance() { delete instance; }

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        static int sWidth, sHeight;

        static GraphicManager *instance;
        GraphicManager();
        ~GraphicManager();
    };
}