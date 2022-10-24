
#pragma once

#include <SDL2/SDL.h>
#include "Scene.hpp"
#include "MainMenu.hpp"

class Core
{
    public:

        /*  Class Methods   */
        bool Init();
        void Clean();

        void Update();
        void Render();

        int Execute();
        void Quit();
        
        /*  Getter Methods   */
        const bool GetRunState() const { return isRunning; }

        /*  Instance    */
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