#include "LevelMenu.hpp"
using namespace Menus;

#include "Game.hpp"

LevelMenu::LevelMenu(EventManager *ev, Game*gm) : events(ev), game(gm)
{
    lvl1.setButton(0, 0, 300, 300);
}
LevelMenu::~LevelMenu()
{
    events = nullptr;
}

void LevelMenu::update()
{
    int x, y;
    SDL_GetMouseState(&x,&y);
    if(events->getMBDown() && x < lvl1.getX() + lvl1.getWidth() && x > lvl1.getX() && y > lvl1.getY() && y < lvl1.getY() +lvl1.getHeight()){
        game->gameState = 1;
    }

}
void LevelMenu::render()
{

}