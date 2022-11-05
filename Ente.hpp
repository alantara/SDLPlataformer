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

public:
    Ente(){};
    ~Ente(){};

    const Sprite* getSprite() const {return &sprite;}
    void setSprite(GraphicManager *gfxM, string p, int f, int c, int w, int h, int m = 1)
    {
        sprite.setSprite(gfxM, p, f, c, w, h, m);
    }

    virtual void update() = 0;
    virtual void render() = 0;
};