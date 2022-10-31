#include "EntityList.hpp"
using namespace Lists;

#include <iostream>

void EntityList::renderAll(SDL_Renderer *renderer)
{

}

void EntityList::updateAll()
{

}

void EntityList::insert(Entity *entity)
{
    EntList.insert(entity);
}