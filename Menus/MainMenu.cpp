#include "MainMenu.hpp"
using namespace Menus;

#include "Game.hpp"

MainMenu::MainMenu(EventManager *ev, Game *gm) : Menu(ev, gm)
{
    sprite.setSprite("assets/bg.jpg", 0, 0, 1920, 1080, 1);

    singleplayer.setButton(10, 600, 400, 100);
    singleplayer.setSprite("assets/Menu/singleplayer.png", 0, 0, 400, 100, 1);

    multiplayer.setButton(10, 700, 400, 100);
    multiplayer.setSprite("assets/Menu/multiplayer.png", 0, 0, 400, 100, 1);

    load.setButton(10, 800, 400, 100);
    load.setSprite("assets/Menu/loadsaved.png", 0, 0, 400, 100, 1);

    exit.setButton(10, 900, 400, 100);
    exit.setSprite("assets/Menu/exit.png", 0, 0, 400, 100, 1);
}
MainMenu::~MainMenu()
{
    events = nullptr;
}

void MainMenu::update()
{
    if (isButtonClicked(singleplayer))
    {
        game->setMultiplayer(false);
        game->setGameState(0);
    }

    if(isButtonClicked(multiplayer))
    {
        game->setMultiplayer(true);
        game->setGameState(0);
    }

    if (isButtonClicked(load))
    {
        //Load Saved
    }

    if(isButtonClicked(exit))
    {
        game->setGameState(-10);
    }
}
void MainMenu::render()
{
    sprite.render();
    singleplayer.render();
    multiplayer.render();
    load.render();
    exit.render();
}