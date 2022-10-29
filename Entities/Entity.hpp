#pragma once

#include "Ente.hpp"
#include "Sprite.hpp"

namespace Entities
{
class Entity : public Ente
{
protected:
    int x;
    int y;
    Sprite sprite;
    bool active;

public:
    Entity(){};
    ~Entity(){};

    int getX() { return x; }
    void setSprite(Sprite spr) { sprite = spr;}
    Sprite getSprite() const {return sprite;}
    virtual void update() = 0;
};
}