#pragma once

#include "Ente.hpp"

#include "EventManager.hpp"
using namespace Managers;

class Game;

namespace Menus
{
    class Menu : public Ente
    {
    protected:
        EventManager *events;
        Game *game;

    public:
        Menu(EventManager *ev, Game* gm) : events(ev), game(gm){};
        ~Menu(){};

        virtual void update() = 0;
        virtual void render() = 0;
    };
}