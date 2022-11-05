#include "CollisionManager.hpp"
#include <iostream>

using namespace Managers;

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

int CollisionManager::isColliding(Entity *ent1, Entity *ent2)
{
    int x1 = ent1->getPosition()->getX();
    int y1 = ent1->getPosition()->getY();
    int w1 = ent1->getPosition()->getW();
    int h1 = ent1->getPosition()->getH();

    int x2 = ent2->getPosition()->getX();
    int y2 = ent2->getPosition()->getY();
    int w2 = ent2->getPosition()->getW();
    int h2 = ent2->getPosition()->getH();

    if (x1 + w1 + 5 > x2 &&
        x1 - 5 < x2 + w2 &&
        y1 + h1 > y2 &&
        y1 < y2 + h2)
    {
        if (x1 < x2)
        {

            ent1->getPosition()->setX(x2 - w1 - 5);
            ent1->getPosition()->setVX(0);

            return 1; // Right Collision
        }
        else if (x1 > x2)
        {

            ent1->getPosition()->setX(x2 + w2 + 5);
            ent1->getPosition()->setVX(0);

            return 3; // Left Collision
        }
    }
    
    if (x1 + w1 > x2 &&
        x1 < x2 + w2 &&
        y1 + h1 + 5 > y2 &&
        y1 - 5 < y2 + h2)
    {
        if (y1 > y2)
        {
            ent1->getPosition()->setY(y2 + h2 + 5);
            ent1->getPosition()->setVY(0);
            return 4; // Top Collision
        }
        else if (y1 < y2)
        {
            ent1->setIsGrounded(true);
            ent1->getPosition()->setY(y2 - h1 - 5);
            ent1->getPosition()->setVY(0);
            return 2; // Bottom Collision
        }
    }
    return 0;
}

void CollisionManager::enemyCollision()
{
}

void CollisionManager::obsCollision()
{
    list<Obstacle *>::iterator it = LOs.begin();
    for (it; it != LOs.end(); it++)
    {
        if(isColliding(static_cast<Entity *>(pl), static_cast<Entity *>(*it)) && (*it)->getHarm())
        {
            pl->takeDamage();
        }
        if(isColliding(static_cast<Entity *>(pl2), static_cast<Entity *>(*it)) && (*it)->getHarm())
        {
            pl2->takeDamage();
        }
    }
}

void CollisionManager::Execute()
{
    obsCollision();
}