
#pragma once

#include <SDL2/SDL.h>
#include <string>

class GraphicManager
{
public:
    GraphicManager();
    ~GraphicManager();

    bool init(std::string title, int width = 1600, int height = 900, Uint32 flags = 0);
    void clean();

    SDL_Window *getWindow() const { return window; }
    SDL_Renderer *getRenderer() const { return renderer; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:

    SDL_Window *window;
    SDL_Renderer *renderer;

    int width, height;
};