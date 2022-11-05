#pragma once

#include <SDL2/SDL.h>

namespace Components
{
    class Position
    {
    private:
        int x;
        int y;
        int w;
        int h;
        int vx;
        int vy;

    public:
        Position() : x(0), y(0), w(0), h(0){};
        ~Position(){};

        void setPosition(int xPos, int yPos, int width, int height, int vX, int vY)
        {
            setX(xPos);
            setY(yPos);
            setW(width);
            setH(height);
            setVX(vX);
            setVY(vY);
        }

        const int getX() const { return x; }
        const int getY() const { return y; }
        const int getW() const { return w; }
        const int getH() const { return h; }
        const int getVX() const { return vx; }
        const int getVY() const { return vy; }

        void setX(int xPos) { x = xPos; }
        void setY(int yPos) { y = yPos; }
        void setW(int width) { w = width; }
        void setH(int height) { h = height; }
        void setVX(int v) { vx = v; }
        void setVY(int v) { vy = v; }
    };
}