#include "PauseMenu.hpp"
using namespace Menus;

#include "Game.hpp"

PauseMenu::PauseMenu(EventManager *ev, Game *gm) : Menu(ev, gm)
{
    sprite.setSprite("assets/bg.jpg", 0, 0, 1920, 1080, 1);

    mainMenu.setButton(10, 700, 400, 100);
    mainMenu.setSprite("assets/Menu/mainmenu.png", 0, 0, 400, 100, 1);

    levelMenu.setButton(10, 800, 400, 100);
    levelMenu.setSprite("assets/Menu/levelmenu.png", 0, 0, 400, 100, 1);
    
    saveLevel.setButton(10, 900, 400, 100);
    saveLevel.setSprite("assets/Menu/savelevel.png", 0, 0, 400, 100, 1);
}
PauseMenu::~PauseMenu()
{
    events = nullptr;
}

void PauseMenu::update()
{
    if (isButtonClicked(mainMenu))
    {
        game->setGameState(-2);
        game->resetLevels();
    }
    if (isButtonClicked(levelMenu))
    {
        game->setGameState(0);
        game->resetLevels();
    }

    if (isButtonClicked(saveLevel))
    {
        //SaveLevel
    }
}
void PauseMenu::render()
{
    sprite.render();
    mainMenu.render();
    levelMenu.render();
    saveLevel.render();
}