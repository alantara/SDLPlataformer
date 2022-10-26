
#pragma once

#include <SDL2/SDL.h>
#include <string>

class Screen
{
    public:

        bool Init(std::string title, int w = 1600, int h = 900, Uint32 flags = 0);
        void Clean();

        void RenderPrepare();
        void RenderPresent();

        SDL_Window* GetWindow() const { return screenWindow; }
        SDL_Renderer* GetRenderer() const { return screenRenderer; }
        int GetWidth() const { return width; }
        int GetHeight() const { return heigth; }

        static Screen* GetInstance()
        {
            return Instance = Instance ? Instance : new Screen();
        }

    private:
        Screen();
        ~Screen();

        SDL_Window* screenWindow;
        SDL_Renderer* screenRenderer;
            
        int width, heigth;

        static Screen* Instance;

};