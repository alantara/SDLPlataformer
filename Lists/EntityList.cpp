#include "EntityList.hpp"
using namespace Lists;

#include <iostream>

void EntityList::renderAll()
{
    List<Entity>::Elemento<Entity> *aux = nullptr;
    aux = EntList.begin();

    while (aux != nullptr)
    {
        aux->GetInfo()->render();

        aux = aux->GetNext();
    }
}

void EntityList::updateAll()
{
    List<Entity>::Elemento<Entity> *aux = nullptr;
    aux = EntList.begin();

    while(aux != nullptr)
    {
        aux->GetInfo()->update();
        aux = aux->GetNext();
    }
}

void EntityList::insert(Entity &entity)
{
    EntList.insert(entity);
}