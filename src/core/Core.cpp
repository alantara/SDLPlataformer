
#include "Core.hpp"

#include <iostream>
#include "Screen.hpp"
#include "Event.hpp"

Core* Core::Instance = nullptr;


/*  Constructor and Destructor  */
Core::Core()
{
    isRunning = true;
}

Core::~Core()
{

}


/*  Initialization and Clean    */
bool Core::Init()
{
    if(!Screen::GetInstance()->Init("Plataformer", 800, 600))
    {
        return false;
    }

    return true;
}

void Core::Clean()
{    
    Screen::GetInstance()->Clean();
}


/*  Logic Functions */
void Core::Update()
{

}

void Core::Render()
{
    Screen::GetInstance()->RenderPrepare();


    Screen::GetInstance()->RenderPresent();
}


/*  Execute */
int Core::Execute()
{
    if(!Init())
    {
        return -1;
    }

    while(isRunning)
    {
        Event::GetInstance()->Listen();
        Update();
        Render();
    }

    Clean();
    
    return 0;
}

void Core::Quit()
{
    isRunning = false;
}