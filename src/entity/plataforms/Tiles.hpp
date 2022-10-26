
#pragma once

#include "Plataforms.hpp"

#include <string>

class Tiles: public Plataforms
{
    public:

        Tiles(std::string type = "UndefinedType", int x = 0, int y = 0) : Plataforms(type, x, y){};
        ~Tiles(){std::cout << "Tile Destroyed" << std::endl;};

        void Render();
        void Update();

        void Clean();

    private:
        
    
};