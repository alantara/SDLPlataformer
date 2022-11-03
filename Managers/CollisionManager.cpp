#include "CollisionManager.hpp"
#include <iostream>

using namespace Managers;

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

int CollisionManager::isColliding(Character *ch, Entity *ent)
{
    int chX, chY, chW, chH, chVx, chVy;
    int entX, entY, entW, entH;

    chVx = ch->getVx();
    chVy = ch->getVy();

    chX = ch->getHitBox()->x;
    chY = ch->getHitBox()->y;
    chW = ch->getHitBox()->w;
    chH = ch->getHitBox()->h;

    entX = ent->getHitBox()->x;
    entY = ent->getHitBox()->y;
    entW = ent->getHitBox()->w;
    entH = ent->getHitBox()->h;

    if (chX + chW + chVx >= entX &&
        chX + chVx <= entX + entW &&
        chY + chH >= entY &&
        chY <= entY + entH)
    {
        if (chVx > 0)
        {
            ch->setX(ent->getX() - ch->getHitBox()->w);
            return 1;
        }
        else
        {
            ch->setX(ent->getX() + ent->getHitBox()->w);
            return 3;
        }
    }

    if (chX + chW >= entX &&
        chX <= entX + entW &&
        chY + chH + chVy >= entY &&
        chY + chVy <= entY + entH)
    {
        if (chVy > 0)
        {
            ch->setY(ent->getY() - ch->getHitBox()->h);
            return 2;
        }
        else
        {
            ch->setY(ent->getY() + ent->getHitBox()->h);
            return 4;
        }
    }
}

void CollisionManager::handleCollision(Player *pl)
{
    vector<Enemy *>::iterator itEne;
    list<Obstacle *>::iterator itObs;
    list<Plataform *>::iterator itPla;

    itEne = LIs.begin();
    itObs = LOs.begin();
    itPla = LPs.begin();

    while (itEne != LIs.end())
    {
        while (itPla != LPs.end())
        {
            if (isColliding(static_cast<Character *>(*itEne), static_cast<Entity *>(*itPla)) % 2 == 1)
            {
                (*itEne)->setVx((*itEne)->getVx() * -1);
            }
            else
            {
                (*itEne)->setVy(0);
            }
            itPla++;
        }
        if (isColliding(static_cast<Character *>(pl), static_cast<Entity *>(*itEne)) == 2)
        {
            (*itEne)->Inactivate();
        }
        else
        {
            pl->takeDamage();
        }
        itEne++;
    }

    for (itObs; itObs != LOs.end(); itObs++)
    {
        int i = isColliding(static_cast<Character *>(pl), static_cast<Entity *>(*itObs));

        if (i % 2 == 1)
        {
            pl->setAx(0);
            pl->setVx(0);
        }
        else
        {
            pl->setVy(0);
        }
    }

    for (itPla; itPla != LPs.end(); itPla++)
    {
        int i = isColliding(static_cast<Character *>(pl), static_cast<Entity *>(*itPla));

        if (i % 2 == 1)
        {
            cout << "Cloosi" << endl;

            pl->setAx(0);
            pl->setVx(0);
        }
        else
        {

            pl->setVy(0);
        }
    }
}