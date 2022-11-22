#pragma once

#include "Menu.hpp"
#include <vector>
using namespace std;

#include "Button.hpp"
#include "Font.hpp"
using namespace Components;

class Game;

namespace Menus
{
    class Leaderboard : public Menu
    {
    private:
        Button mainMenu;
        vector<Font*> names;

    public:
        Leaderboard(EventManager *ev, Game*gm);
        ~Leaderboard();
        void clean();

        void setNames();
        void renderNames();
        void update();
        void render();
    };
}