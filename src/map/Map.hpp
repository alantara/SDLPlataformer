
#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include "../gfx/TextureManager.hpp"

class Map
{
    public:
        Map();
        ~Map();

        /*  Class Methods   */

        void Render(SDL_Renderer* renderer, TextureManager* gfxManager);

    private:

};