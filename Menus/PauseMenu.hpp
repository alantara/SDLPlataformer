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
        Button mainMenu;
        Button levelMenu;
        Button saveLevel;

        int lastLevel;

    public:
        PauseMenu(EventManager *ev, Game *gm);
        ~PauseMenu();

        void setLastLevel(int l) { lastLevel = l; }

        void update();
        void render();
    };
}