
#pragma once

#include <SDL2/SDL.h>

class EventManager
{
public:
    EventManager();
    ~EventManager();

    void listen(bool &isRunning);
    void keyUpdate();

    bool getKeyDown(SDL_Scancode key) { return (keyStates[key] == 1); }

private:

    SDL_Event outputEvent;
    const Uint8 *keyStates;
};