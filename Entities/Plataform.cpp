
#include "Plataform.hpp"

#include <iostream>

using namespace Entities;

Plataform::Plataform(bool act)
{
    id = 3;
    active = act;
}

Plataform::~Plataform()
{
}

void Plataform::update()
{
    this->setHitBox({position.getX(), position.getY(), sprite.getWidth(), sprite.getHeight()});
}