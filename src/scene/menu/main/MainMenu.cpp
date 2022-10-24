
#include "MainMenu.hpp"

#include <iostream>
#include "Screen.hpp"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{

}

void MainMenu::Render()
{
    SDL_SetRenderDrawColor(Screen::GetInstance()->GetRenderer(), 0, 0, 255, 255);
}

void MainMenu::Update()
{

}