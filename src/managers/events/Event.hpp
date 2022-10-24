
#pragma once

#include <SDL2/SDL.h>

class Event
{
    public:

        /*  Class Methods   */
        void Listen();
        void KeyUpdate();

        /*  Getter Methods   */
        bool GetKeyDown(SDL_Scancode key) { return (m_KeyStates[key] == 1); }

        /*  Instance    */
        static Event* GetInstance()
        {
            return Instance = Instance ? Instance : new Event();
        }

    private:
        Event();
        ~Event();

        SDL_Event outputEvent;
        const Uint8* m_KeyStates;

        static Event* Instance;

};