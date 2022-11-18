#pragma once

#include "Menu.hpp"

#include "Button.hpp"
using namespace Components;

class Game;

namespace Menus
{
    class MainMenu : public Menu
    {
    private:
        Button singleplayer;
        Button multiplayer;
        Button load;
        Button exit;

    public:
        MainMenu(EventManager *ev, Game *gm);
        ~MainMenu();

        void update();
        void render();
    };
}