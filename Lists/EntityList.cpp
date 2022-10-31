#include "EntityList.hpp"
using namespace Lists;

#include <iostream>

void EntityList::renderAll(SDL_Renderer *renderer)
{
    List<Entity>::Element<Entity> *aux = nullptr;
    aux = entList.begin();

    while (aux != nullptr)
    {
        aux->getData().render(renderer);
        aux = aux->getNext();
    }
}

void EntityList::updateAll()
{
}

void EntityList::insert(Entity entity)
{
    entList.insert(entity);
}