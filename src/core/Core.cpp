
#include "Core.hpp"

#include <iostream>

#include "Screen.hpp"
#include "Event.hpp"
#include "ScenesM.hpp"
#include "Frame.hpp"
#include "EntityM.hpp"

Core* Core::Instance = nullptr;

Core::Core()
{
    isRunning = true;
    mainMenu = nullptr;
    Frame::GetInstance()->setFrameRate(60);
}

Core::~Core()
{

}


bool Core::Init()
{
    if(!Screen::GetInstance()->Init("Plataformer", 800, 600))
    {
        return false;
    }

    mainMenu = new MainMenu();
    ScenesM::GetInstance()->CreateScene("mainMenu", static_cast<Scene*>(mainMenu));
    ScenesM::GetInstance()->SetActiveScene("mainMenu");

    return true;
}

void Core::Clean()
{    
    Screen::GetInstance()->Clean();
    ScenesM::GetInstance()->Clean();
    EntityM::GetInstance()->Clean();
}

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


void Core::Update()
{
    Frame::GetInstance()->FrameStart();

    ScenesM::GetInstance()->UpdateScene();

    EntityM::GetInstance()->Update();

    Frame::GetInstance()->FrameEnd();
}

void Core::Render()
{
    Screen::GetInstance()->RenderPrepare();

    ScenesM::GetInstance()->RenderScene();

    EntityM::GetInstance()->Render();

    Screen::GetInstance()->RenderPresent();
}