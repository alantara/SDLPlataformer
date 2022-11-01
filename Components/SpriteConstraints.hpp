#pragma once

#include <SDL2/SDL.h>
#include <string>
using namespace std;

namespace Components
{
    class SpriteConstraints
    {
    private:
        string path;
        int frame;
        int column;
        int width;
        int height;

    public:
        SpriteConstraints(string p, int f, int c, int w, int h) : path(p), frame(f), column(c), width(w), height(h){};
        ~SpriteConstraints(){};

        const string getPath() const { return path; }
        const int getFrame() const { return frame; }
        const int getColumn() const { return column; }
        const int getWidth() const { return width; }
        const int getHeight() const { return height; }

        string setPath(string p) { return path = p; }
        bool setFrame(int f) { return frame = f; }
        bool setColumn(int c) { return column = c; }
        bool setWidth(int w) { return width = w; }
        bool setHeight(int h) { return height = h; }
    };
}