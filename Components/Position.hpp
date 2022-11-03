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
        Position() : x(0), y(0){};
        ~Position(){};

        void setPosition(int xPos, int yPos)
        {
            setX(xPos);
            setY(yPos);
        }

        const int getX() const { return x; }
        const int getY() const { return y; }

        void setX(int xPos) { x = xPos; }
        void setY(int yPos) { y = yPos; }
    };
}