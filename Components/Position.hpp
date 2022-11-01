#pragma once

#include <SDL2/SDL.h>

namespace Components
{
    class Position
    {
    private:
        int x;
        int y;

    public:
        Position(int xPos, int yPos) : x(xPos), y(yPos){};
        ~Position(){};

        const int getX() const { return x; }
        const int getY() const { return y; }

        int getX(int xPos) { return x = xPos; }
        int getY(int yPos) { return y = yPos; }
    };
}