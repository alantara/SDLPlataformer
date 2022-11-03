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

        int frame;
        int column;
        int width;
        int height;
        int multiplier;

        GraphicManager *gfx;

    public:
        Sprite() : gfx(nullptr), path(""), frame(0), column(0), width(0), height(0), multiplier(1), texture(nullptr){};
        ~Sprite()
        {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }

        void setSprite(GraphicManager *gfxM, string p, int f, int c, int w, int h, int m = 1)
        {
            setGFXPointer(gfxM);
            
            setPath(p);
            setTexture(p);

            setFrame(f);
            setColumn(c);
            setWidth(w);
            setHeight(h);
            setMultiplier(m);

        }

        const string getPath() const { return path; }
        const SDL_Texture *getTexture() const { return texture; }
        const int getFrame() const { return frame; }
        const int getColumn() const { return column; }
        const int getWidth() const { return width; }
        const int getHeight() const { return height; }
        const int getMultiplier() const { return multiplier; }

        void setPath(string p) { path = p; }
        void setTexture(string p)
        {
            if (texture != nullptr)
            {
                SDL_DestroyTexture(texture);
            }

            SDL_Texture *tx = IMG_LoadTexture(gfx->getRenderer(), p.c_str());
            if (tx == nullptr)
            {
                std::cout << "Texture could not be loaded: " << SDL_GetError() << std::endl;
                return;
            }

            texture = tx;
        }
        void setFrame(int f) { frame = f; }
        void setColumn(int c) { column = c; }
        void setWidth(int w) { width = w; }
        void setHeight(int h) { height = h; }
        void setMultiplier(int m) { multiplier = m; }
        void setGFXPointer(GraphicManager *gfxM) { gfx = gfxM; }

        void render(int x = 0, int y = 0)
        {
            SDL_Rect srcRect = {column * width, frame * height, width, height};
            SDL_Rect dstRect = {x, y, width * multiplier, height * multiplier};

            SDL_RenderCopy(gfx->getRenderer(), texture, &srcRect, &dstRect);
        }
    };
}