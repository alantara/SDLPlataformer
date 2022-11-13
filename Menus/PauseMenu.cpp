#include "PauseMenu.hpp"
using namespace Menus;

#include "Game.hpp"

PauseMenu::PauseMenu(EventManager *ev, Game *gm) : Menu(ev, gm)
{
    sprite.setSprite("assets/bg.jpg", 0, 0, 1920, 1080, 1);

    menu.setButton(40, 40, 225, 225);
    menu.setSprite("assets/menu.png", 0, 0, 225, 225, 1);

    save.setButton(1600, 40, 225, 225);
    save.setSprite("assets/save.png", 0, 0, 225, 225, 1);
}
PauseMenu::~PauseMenu()
{
    events = nullptr;
}

void PauseMenu::update()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (events->getMBDown() && x < menu.getX() + menu.getWidth() && x > menu.getX() && y > menu.getY() && y < menu.getY() + menu.getHeight())
    {
        game->gameState = 0;
    }

    if (events->getMBDown() && x < save.getX() + save.getWidth() && x > save.getX() && y > save.getY() && y < save.getY() + save.getHeight())
    {
        game->gameState = -2;
    }
}
void PauseMenu::render()
{
    sprite.render();
    menu.render();
    save.render();
}