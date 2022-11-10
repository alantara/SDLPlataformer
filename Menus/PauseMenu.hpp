#pragma once

#include "Menu.hpp"

#include "EventManager.hpp"
using namespace Managers;
#include "Button.hpp"
using namespace Components;

class Game;

namespace Menus
{
    class PauseMenu : public Menu
    {
    private:
        Button menu;
        Button save;

    public:
        PauseMenu(EventManager *ev, Game *gm);
        ~PauseMenu();

        void update();
        void render();
    };
}