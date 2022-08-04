#include <core/core.hpp>

int Core::CreateWindow(char *windowTitle, int windowWidth, int windowHeight)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) return 0;

    SDL_Window *window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, 0);
    if(!window) return 0;

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer) return 0;

    Core::window = window;
    Core::renderer = renderer;
    return 1;
}