
#include "Event.hpp"

#include "Core.hpp"

Event* Event::Instance = nullptr;

/*  Constructor and Destructor  */
Event::Event()
{
    
}

Event::~Event()
{

}



/*  Logic Functions */
void Event::Listen()
{
    while(SDL_PollEvent(&outputEvent))
    {
        switch (outputEvent.type)
        {
            case SDL_QUIT: Core::GetInstance()->Quit(); break;
            case SDL_KEYDOWN: KeyUpdate(); break;
            case SDL_KEYUP: KeyUpdate(); break;
        }
    }
}

void Event::KeyUpdate()
{
    m_KeyStates = SDL_GetKeyboardState(nullptr);
}
