#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SDL.h>

class EventHandler
{
    public:
        static EventHandler* GetInstance()
        {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new EventHandler();
        }

        void Listen();
        bool GetKeyDown(SDL_Scancode key);

    private:
        EventHandler() {};
        static EventHandler* s_Instance;

        void KeyUpdate();
        const Uint8* m_KeyStates;
};

#endif // EVENTHANDLER_H
