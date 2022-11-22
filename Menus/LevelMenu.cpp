#include "LevelMenu.hpp"
using namespace Menus;

#include "Game.hpp"

LevelMenu::LevelMenu(EventManager *ev, Game *gm) : Menu(ev, gm)
{
    sprite.setSprite("assets/bg.jpg", 0, 0, 1920, 1080, 1);

    lvl1.setButton(760, 700, 400, 100);
    lvl1.setSprite("assets/Menu/level1.png", 0, 0, 400, 100, 1);

    lvl2.setButton(760, 800, 400, 100);
    lvl2.setSprite("assets/Menu/level2.png", 0, 0, 400, 100, 1);

    mainMenu.setButton(760, 900, 400, 100);
    mainMenu.setSprite("assets/Menu/mainmenu.png", 0, 0, 400, 100, 1);
}
LevelMenu::~LevelMenu()
{
    events = nullptr;
}

void LevelMenu::update()
{
    if (isButtonClicked(lvl1))
    {
        game->Level1Initialize();
        game->setGameState(1);
    }

    if (isButtonClicked(lvl2))
    {
        game->Level2Initialize();
        game->setGameState(2);
    }

    if (isButtonClicked(mainMenu))
    {
        game->setGameState(-2);
    }
}
void LevelMenu::render()
{
    sprite.render();
    lvl1.render();
    lvl2.render();
    mainMenu.render();
}