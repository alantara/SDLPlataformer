

#pragma once 

#include "Menu.hpp"
#include "Map.hpp"

class MainMenu : public Menu
{
    public:

        MainMenu();
        ~MainMenu();

        void Render();
        void Update();

    private:
        Map* map;
};