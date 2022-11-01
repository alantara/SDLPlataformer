
#include "Plataform.hpp"

#include <iostream>

using namespace Entities;

Plataform::Plataform(GraphicManager *graphM, int xpos, int ypos) : Entity(graphM, xpos, ypos)
{
    id = 3;
}

Plataform::~Plataform()
{
}

void Plataform::update()
{
}