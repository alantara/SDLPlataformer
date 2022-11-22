#include "EntityList.hpp"
using namespace Lists;

#include <iostream>
#include <fstream>
using namespace std;

#include "Plataform.hpp"

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

void EntityList::save(string name, int lvlnum)
{
    List<Entity *>::Element<Entity *> *aux = nullptr;
    aux = entList.begin();

    ofstream arq;
    arq.open(name, ios::out | ios::trunc);
    arq << lvlnum << endl;
    while (aux != nullptr)
    {

        aux->getData()->save(arq);
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
        if (aux->getData()->getIsActive() && (aux->getData()->getType() == "Enemy"))
            i++;
        aux = aux->getNext();
    }
    return i;
}
