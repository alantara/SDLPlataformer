
#pragma once

#include <SDL2/SDL.h>

#include "MainMenu.hpp"

class Core
{
    public:

        bool Init();
        int Execute();
        void Clean();
        void Quit();

        void Update();
        void Render();

        const bool GetRunState() const { return isRunning; }

        static Core* GetInstance()
        {
            return Instance = Instance ? Instance : new Core();
        }
        
    private:
        Core();
        ~Core();

        bool isRunning;

        MainMenu* mainMenu;

        static Core* Instance;
};