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
    List<Entity *>::Element<Entity *> *aux2 = nullptr;
    aux = entList.begin();
    while (aux != nullptr)
    {
        aux2 = aux->getNext();
        if (aux->getData()->getDeletable())
        {
            delete (aux->getData());
        }
        delete aux;
        aux = aux2;
    }
    entList.clean();
}

void EntityList::save(string name)
{
    List<Entity *>::Element<Entity *> *aux = nullptr;
    aux = entList.begin();

    ofstream arq;
    arq.open(name, ios::out | ios::trunc);

    while (aux != nullptr)
    {

        Physics *phy = aux->getData()->getPhysics();

        arq << aux->getData()->getEntId() << " " << (aux->getData()->getIsActive() ? 1 : 0) << " " << phy->getXPosition() << " " << phy->getYPosition() << endl;
        aux = aux->getNext();
    }

    arq.close();
}

int EntityList::getEnemySize()
{
    int i = 0;
    List<Entity *>::Element<Entity *> *aux = nullptr;
    aux = entList.begin();

    while (aux != nullptr)
    {
        if (aux->getData()->getIsActive() && (aux->getData()->getEntId() == 2 || aux->getData()->getEntId() == 3 || aux->getData()->getEntId() == 4))
            i++;
        aux = aux->getNext();
    }
    return i;
}
