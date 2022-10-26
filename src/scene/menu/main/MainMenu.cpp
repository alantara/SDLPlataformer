
#include "MainMenu.hpp"

#include <iostream>
#include "Screen.hpp"
#include "Tileset.hpp"

MainMenu::MainMenu()
{
    Tileset* ts = new Tileset("assets/texture.png", 22, 24, 8, 8);
    map = new Map("assets/data.dat", ts);
}

MainMenu::~MainMenu()
{
    delete map;
    map = nullptr;
}

void MainMenu::Render()
{
    SDL_SetRenderDrawColor(Screen::GetInstance()->GetRenderer(), 0, 0, 255, 255);
}

void MainMenu::Update()
{

}