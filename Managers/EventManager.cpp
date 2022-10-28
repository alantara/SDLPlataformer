#include "EventManager.hpp"

EventManager::EventManager()
{
    keyStates = SDL_GetKeyboardState(nullptr);
}

EventManager::~EventManager()
{
    keyStates = nullptr;
}

bool EventManager::listen()
{
    while (SDL_PollEvent(&outputEvent))
    {
        switch (outputEvent.type)
        {
        case SDL_QUIT:
            return false;
            break;
        case SDL_KEYDOWN:
            keyUpdate();
            break;
        case SDL_KEYUP:
            keyUpdate();
            break;
        }
    }

    return true;
}

void EventManager::keyUpdate()
{
    keyStates = SDL_GetKeyboardState(nullptr);
}