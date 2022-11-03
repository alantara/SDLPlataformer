#include "EventManager.hpp"
using namespace Managers;

#include <iostream>
using namespace std;

EventManager::EventManager() : 
keyStates(SDL_GetKeyboardState(nullptr))
{
    cout << "Event Manager Initialized" << endl;
}

EventManager::~EventManager()
{
    keyStates = nullptr;
    cout << "Event Manager Deleted" << endl;
}

void EventManager::listen(bool &isRunning)
{
    while (SDL_PollEvent(&outputEvent))
    {
        switch (outputEvent.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            keyUpdate();
            break;
        case SDL_KEYUP:
            keyUpdate();
            break;
        }
    }
}

void EventManager::keyUpdate()
{
    keyStates = SDL_GetKeyboardState(nullptr);
}