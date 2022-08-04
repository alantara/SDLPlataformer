#pragma once
#include <SDL.h>

class Core
{
    public:
        SDL_Window* window;
        SDL_Renderer* renderer;

        int CreateWindow(char* windowTitle, int windowWidth, int windowHeight);
};
