#include "EventHandler.h"

#include "../core/Engine.h"

EventHandler* EventHandler::s_Instance = nullptr;

EventHandler::EventHandler()
{
    m_KeyStates = SDL_GetKeyboardState(nullptr);
}

void EventHandler::Listen()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT: Engine::GetInstance()->Quit(); break;
        case SDL_KEYDOWN: KeyUpdate(); break;
        case SDL_KEYUP: KeyUpdate(); break;
    }
}

bool EventHandler::GetKeyDown(SDL_Scancode key)
{
    return (m_KeyStates[key] == 1);
}

void EventHandler::KeyUpdate()
{
    m_KeyStates = SDL_GetKeyboardState(nullptr);
}
