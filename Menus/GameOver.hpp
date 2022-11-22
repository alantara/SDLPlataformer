#pragma once

#include "Menu.hpp"
#include "Button.hpp"
#include "Font.hpp"
using namespace Components;

namespace Menus
{
    class GameOver : public Menu
    {
    private:
        Button playAgain;
        Button mainMenu;
        Button input;

        int pts;

        Font points;
        Font name;

    public:
        GameOver(EventManager* ev, Game* gm);
        ~GameOver();

        void setPoints(int p);
        void getInput();
        void update();
        void render();
    };
}