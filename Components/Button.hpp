#pragma once

namespace Components
{
    class Button
    {
    private:
        int x, y;
        int width, height;

    public:
        Button() : x(0), y(0), width(0), height(0){};
        ~Button(){};

        void setButton(int xPos, int yPos, int w, int h)
        {
            
        }

        const int getX() const { return x; }
        const int getY() const { return y; }
        const int getHeight() const { return height; }
        const int getWidth() const { return width; }

        void setX(int xPos) { x= xPos; }
        void setY(int yPos) { y= yPos; }
        void setWidth(int w) {width = w; }
        void setHeight(int h) {height = h; }
    };
}