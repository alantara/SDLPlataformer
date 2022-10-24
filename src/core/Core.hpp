
#pragma once

#include <SDL2/SDL.h>

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

        static Core* Instance;
};