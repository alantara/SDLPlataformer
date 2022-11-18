#pragma once

#include "Menu.hpp"

#include "Button.hpp"
using namespace Components;

class Game;

namespace Menus
{
    class LevelMenu : public Menu
    {
    private:
        Button lvl1;
        Button lvl2;
        Button mainMenu;

    public:
        LevelMenu(EventManager *ev, Game*gm);
        ~LevelMenu();

        void update();
        void render();
    };
}