#pragma once

#include "Menu.hpp"

#include "EventManager.hpp"
using namespace Managers;
#include "Button.hpp"
using namespace Components;

namespace Menus
{
    class LevelMenu : public Menu
    {
    private:
        EventManager *events;
        Button lvl1;
        Button lvl2;

    public:
        LevelMenu(GraphicManager *gfxM, EventManager *ev);
        ~LevelMenu();

        void update();
        void render();
    };
}