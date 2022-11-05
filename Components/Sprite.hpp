#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>
using namespace std;

#include "GraphicManager.hpp"
using namespace Managers;

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
        Sprite() : path(""), row(0), column(0), width(0), height(0), multiplier(1), texture(nullptr){};
        ~Sprite()
        {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }

        void setSprite(GraphicManager *gfxM, string p, int c, int r, int w, int h, int m = 1)
        {
            setPath(p);
            setTexture(gfxM, p);

            setRow(r);
            setColumn(c);
            setWidth(w);
            setHeight(h);
            setMultiplier(m);
        }

        const string getPath() const { return path; }
        const SDL_Texture *getTexture() const { return texture; }
        const int getRow() const { return row; }
        const int getColumn() const { return column; }
        const int getWidth() const { return width; }
        const int getHeight() const { return height; }
        const int getMultiplier() const { return multiplier; }

        void setPath(string p) { path = p; }
        void setTexture(GraphicManager *gfxM, string p)
        {
            if (texture != nullptr)
            {
                SDL_DestroyTexture(texture);
            }

            SDL_Texture *tx = IMG_LoadTexture(gfxM->getRenderer(), p.c_str());
            if (tx == nullptr)
            {
                std::cout << "Texture could not be loaded: " << SDL_GetError() << std::endl;
                return;
            }

            texture = tx;
        }
        void setRow(int r) { row = r; }
        void setColumn(int c) { column = c; }
        void setWidth(int w) { width = w; }
        void setHeight(int h) { height = h; }
        void setMultiplier(int m) { multiplier = m; }

        void render(GraphicManager *gfxM, int x = 0, int y = 0)
        {
            SDL_Rect srcRect = {column * width, row * height, width, height};
            SDL_Rect dstRect = {x, y, width * multiplier, height * multiplier};

            SDL_RenderCopy(gfxM->getRenderer(), texture, &srcRect, &dstRect);
        }
    };
}