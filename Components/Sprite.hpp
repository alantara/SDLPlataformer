#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>
using namespace std;

namespace Components
{
    class Sprite
    {
    private:
        string path;
        SDL_Texture *texture;

        int row;
        int column;
        int width;
        int height;
        int multiplier;

    public:
        Sprite();
        ~Sprite();

        void setSprite(string p, int c, int r, int w, int h, int m = 1);

        const string getPath() const { return path; }
        const SDL_Texture *getTexture() const { return texture; }
        const int getRow() const { return row; }
        const int getColumn() const { return column; }
        const int getWidth() const { return width; }
        const int getHeight() const { return height; }
        const int getMultiplier() const { return multiplier; }

        void setPath(string p) { path = p; }
        void setTexture(string p);
        void setRow(int r) { row = r; }
        void setColumn(int c) { column = c; }
        void setWidth(int w) { width = w; }
        void setHeight(int h) { height = h; }
        void setMultiplier(int m) { multiplier = m; }

        void render(int x = 0, int y = 0, int moveDir = 1);

    };
}