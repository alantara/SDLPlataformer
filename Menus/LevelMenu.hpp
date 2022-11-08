#pragma once

#include "Menu.hpp"

#include "EventManager.hpp"
using namespace Managers;
#include "Button.hpp"
using namespace Components;

class Game;

namespace Menus
{
    class LevelMenu : public Menu
    {
    private:
        EventManager *events;
        Button lvl1;
        Button lvl2;

        Game *game;

    public:
        LevelMenu(EventManager *ev, Game*gm);
        ~LevelMenu();

        void update();
        void render();
    };
}