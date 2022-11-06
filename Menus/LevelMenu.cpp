#include "LevelMenu.hpp"
using namespace Menus;

LevelMenu::LevelMenu(GraphicManager *gfxM, EventManager *ev) : Menu(gfxM), events(ev)
{
    lvl1.setButton(0, 0, 300, 300);
}
LevelMenu::~LevelMenu()
{
    events = nullptr;
}

void LevelMenu::update()
{
    if(events->getMBDown()){
        //COMO PASSAR O GAMESTATE DAQUI
    }

}
void LevelMenu::render()
{

}