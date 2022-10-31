#pragma once

#include "GraphicManager.hpp"

class Ente
{
protected:
    int id;
    GraphicManager *gfx;

public:
    Ente(GraphicManager *graphM = nullptr) : gfx(graphM){};
    ~Ente(){};

    virtual void update() = 0;
    virtual void render(){};
};