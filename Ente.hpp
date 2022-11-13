#pragma once

#include "GraphicManager.hpp"
using namespace Managers;

#include "Sprite.hpp"
using namespace Components;

class Ente
{
private:
    static int enteSize;
    int id;

protected:
    static GraphicManager *gfx;
    Sprite sprite;

public:
    Ente();
    ~Ente();

    int getEnteSize() { return enteSize; }
    int getID() { return id; }
    void setSprite(string p, int f, int c, int w, int h, int m = 1);

    virtual void update() = 0;
    virtual void render() = 0;
};
