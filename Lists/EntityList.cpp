#include "EntityList.hpp"
using namespace Lists;

#include <iostream>
#include <fstream>
using namespace std;

EntityList::EntityList() : entList()
{
}

EntityList::~EntityList()
{
}

void EntityList::renderAll()
{
    List<Entity *>::Element<Entity *> *aux = nullptr;
    aux = entList.begin();

    while (aux != nullptr)
    {
        aux->getData()->render();
        aux = aux->getNext();
    }
}

void EntityList::updateAll()
{
    List<Entity *>::Element<Entity *> *aux = nullptr;
    aux = entList.begin();

    while (aux != nullptr)
    {
        aux->getData()->update();
        aux = aux->getNext();
    }
}

void EntityList::insert(Entity *entity)
{
    entList.insert(entity);
}

void EntityList::clean()
{
    List<Entity *>::Element<Entity *> *aux = nullptr;
    aux = entList.begin();
    while (aux != nullptr)
    {
        if (aux->getData()->getDeletable())
            delete (aux->getData());
        aux = aux->getNext();
    }
    entList.clean();
}

void EntityList::save(string name)
{
    List<Entity *>::Element<Entity *> *aux = nullptr;
    aux = entList.begin();

    ofstream arq;
    arq.open(name);

    while (aux != nullptr)
    {
        Physics *phy = aux->getData()->getPhysics();

        arq << phy->getXPosition() << " " << phy->getYPosition() << endl;
        aux = aux->getNext();
    }

    arq.close();
}