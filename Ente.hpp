#pragma once

#include "GraphicManager.hpp"
using namespace Managers;

#include "Sprite.hpp"
using namespace Components;

class Ente
{
protected:
    int id;
    Sprite sprite;

    GraphicManager *gfx;

public:
    Ente(GraphicManager *p_graphM) : gfx(p_graphM), id(0)
    {
        cout << "Ente Created! id: " << id << endl;
    }
    ~Ente()
    {
        cout << "Ente Destroyed! id: " << id << endl;
        gfx = nullptr;
    }

    void setSprite(GraphicManager *gfxM, string p, int f, int c, int w, int h, int m = 1)
    {
        gfx = gfxM;
        sprite.setSprite(gfxM, p, f, c, w, h, m);
    }

    virtual void update() = 0;
    virtual void render() = 0;
};