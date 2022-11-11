#include "LevelMenu.hpp"
using namespace Menus;

#include "Game.hpp"

LevelMenu::LevelMenu(EventManager *ev, Game *gm) : Menu(ev, gm)
{
    sprite.setSprite(gfx, "assets/bg.jpg", 0, 0, 1920, 1080, 1);

    lvl1.setButton(635, 700, 225, 225);
    lvl1.setSprite("assets/lvl1.png", 0, 0, 225, 225, 1);

    lvl2.setButton(1060, 700, 225, 225);
    lvl2.setSprite("assets/lvl2.png", 0, 0, 225, 225, 1);
}
LevelMenu::~LevelMenu()
{
    events = nullptr;
}

void LevelMenu::update()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (events->getMBDown() && x < lvl1.getX() + lvl1.getWidth() && x > lvl1.getX() && y > lvl1.getY() && y < lvl1.getY() + lvl1.getHeight())
    {
        game->gameState = 1;
    }

    if (events->getMBDown() && x < lvl2.getX() + lvl2.getWidth() && x > lvl2.getX() && y > lvl2.getY() && y < lvl2.getY() + lvl2.getHeight())
    {
        game->gameState = 2;
    }
}
void LevelMenu::render()
{
    sprite.render(gfx, 0, 0);
    lvl1.render();
    lvl2.render();
}