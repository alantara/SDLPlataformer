#include "MainMenu.hpp"
using namespace Menus;

#include "Game.hpp"

MainMenu::MainMenu(EventManager *ev, Game *gm) : Menu(ev, gm)
{
    sprite.setSprite("assets/bg.jpg", 0, 0, 1920, 1080, 1);

    singleplayer.setButton(760, 600, 400, 100);
    singleplayer.setSprite("assets/Menu/singleplayer.png", 0, 0, 400, 100, 1);

    multiplayer.setButton(760, 700, 400, 100);
    multiplayer.setSprite("assets/Menu/multiplayer.png", 0, 0, 400, 100, 1);

    load.setButton(760, 800, 400, 100);
    load.setSprite("assets/Menu/loadsaved.png", 0, 0, 400, 100, 1);

    exit.setButton(100, 900, 400, 100);
    exit.setSprite("assets/Menu/exit.png", 0, 0, 400, 100, 1);

    ld.setButton(760, 900, 400, 100);
    ld.setSprite("assets/Menu/leaderboard.png", 0, 0, 400, 100, 1);
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

    if (isButtonClicked(multiplayer))
    {
        game->setMultiplayer(true);
        game->setGameState(0);
    }

    if (isButtonClicked(load))
    {
        if (game->loadLVL1() == 0)
        {
            game->setGameState(1);
        }
    }

    if (isButtonClicked(exit))
    {
        game->setGameState(-10);
    }

    if(isButtonClicked(ld))
    {
        game->upLeaderboard();
        game->setGameState(4);
    }
}
void MainMenu::render()
{
    sprite.render();
    singleplayer.render();
    multiplayer.render();
    load.render();
    exit.render();
    ld.render();
}