
#pragma once

#include <SDL2/SDL.h>

class Frame
{
    public:

        void FrameStart();
        void FrameEnd();

        void setFrameRate(int fps);

        static Frame* GetInstance()
        {
            return Instance = Instance ? Instance : new Frame();
        }

    private:

        Frame(int fps = 60);
        ~Frame();

        int FPS;
        float frameDelay;
        Uint32 frameStart;

        static Frame* Instance;

};