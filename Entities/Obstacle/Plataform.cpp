
#include "Plataform.hpp"

using namespace Entities;
using namespace Obstacles;

Plataform::Plataform(GraphicManager *p_graphM) : Obstacle(p_graphM)
{
}

Plataform::~Plataform()
{
}

void Plataform::update()
{
    move();
}