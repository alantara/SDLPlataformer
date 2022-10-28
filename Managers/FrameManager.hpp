#pragma once

#include <SDL2/SDL.h>

class FrameManager
{
private:
    int FPS;
    float frameDelay;
    Uint32 frameStart;

public:
    FrameManager(int fps = 60);
    ~FrameManager();

    void FrameStart();
    void FrameEnd();

    void SetFrameRate(int fps) {FPS = fps;}
};
