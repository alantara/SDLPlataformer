
#pragma once

#include <SDL2/SDL.h>
namespace Managers
{
    class EventManager
    {
    public:
        EventManager();
        ~EventManager();

        void listen(bool &isRunning);
        void keyUpdate();

        bool getKeyDown(SDL_Scancode key) { return (keyStates[key] == 1); }
        bool getMBDown() { return mouseClick; }

        int getMouseX() { return mouseX; }
        int getMouseY() { return mouseY; }
        bool getMouseClick() { return mouseClick; }

    private:
        int mouseX, mouseY;
        bool mouseClick, lastMouseClick;
        SDL_Event outputEvent;
        const Uint8 *keyStates;
    };
}