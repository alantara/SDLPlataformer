#pragma once

#include "Ente.hpp"
#include "GraphicManager.hpp"
using namespace Managers;

namespace Menus
{
    class Menu : public Ente
    {
    public:
        Menu() {};
        ~Menu(){};

        virtual void update() = 0;
        virtual void render() = 0;
    };
}