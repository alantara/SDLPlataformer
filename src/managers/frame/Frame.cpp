
#include "Frame.hpp"

#include <iostream>

Frame* Frame::Instance = nullptr;

Frame::Frame(int fps)
{
    setFrameRate(fps);
}

Frame::~Frame()
{

}



void Frame::FrameStart()
{
    frameStart = SDL_GetTicks();
}

void Frame::FrameEnd()
{
    int frameTime = SDL_GetTicks() - frameStart;

    if(frameDelay > frameTime)
    {
        SDL_Delay(frameDelay - frameTime);
    }
}

void Frame::setFrameRate(int fps)
{
    FPS = fps;
    frameDelay = (float)1000 / FPS;
}