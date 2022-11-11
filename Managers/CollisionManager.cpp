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
    int x1 = ent1->getPhysics()->getXPosition();
    int y1 = ent1->getPhysics()->getYPosition();
    int w1 = ent1->getPhysics()->getW();
    int h1 = ent1->getPhysics()->getH();

    int x2 = ent2->getPhysics()->getXPosition();
    int y2 = ent2->getPhysics()->getYPosition();
    int w2 = ent2->getPhysics()->getW();
    int h2 = ent2->getPhysics()->getH();

    if (x1 + w1 > x2 &&
        x1 < x2 + w2 &&
        y1 + h1 + 5 > y2 &&
        y1 - 5 < y2 + h2)
    {
        if (y1 > y2)
        {
            ent1->getPhysics()->setYPosition(y2 + h2 + 6);
            ent1->getPhysics()->setYVelocity(0);
            return 4; // Top Collision
        }
        else if (y1 < y2)
        {
            ent1->setIsGrounded(true);
            ent1->getPhysics()->setYPosition(y2 - h1 - 6);
            ent1->getPhysics()->setYVelocity(0);
            return 2; // Bottom Collision
        }
    }

    if (x1 + w1 + 5 > x2 &&
        x1 - 5 < x2 + w2 &&
        y1 + h1 > y2 &&
        y1 < y2 + h2)
    {
        if (x1 < x2)
        {

            ent1->getPhysics()->setXPosition(x2 - w1 - 6);

            return 1; // Right Collision
        }
        else if (x1 > x2)
        {

            ent1->getPhysics()->setXPosition(x2 + w2 + 6);

            return 3; // Left Collision
        }
    }

    return 0;
}

void CollisionManager::enemyCollision()
{
    vector<Enemy *>::iterator it;
    list<Obstacle *>::iterator it2;

    for (it = LIs.begin(); it != LIs.end(); it++)
    {
        for (it2 = LOs.begin(); it2 != LOs.end(); it2++)
        {
            if (isColliding(static_cast<Entity *>(*it), static_cast<Entity *>(*it2)) % 2 == 1)
            {
                (*it)->getPhysics()->setMoveDirection(-(*it)->getPhysics()->getMoveDirection());
                (*it)->getPhysics()->setXVelocity(-(*it)->getPhysics()->getXVelocity());
            }
        }
    }
}

void CollisionManager::obsCollision()
{
    list<Obstacle *>::iterator it;
    list<Obstacle *>::iterator it2;

    for (it = LOs.begin(); it != LOs.end(); it++)
    {
        if (isColliding(static_cast<Entity *>(pl), static_cast<Entity *>(*it)) && (*it)->getHarm())
        {
            pl->takeDamage();
            pl->getPhysics()->setXVelocity(45 * pl->getPhysics()->getMoveDirection());
            pl->getPhysics()->setXPosition(pl->getPhysics()->getXPosition() + pl->getPhysics()->getXVelocity());
            pl->getPhysics()->setYVelocity(-15);
            pl->getPhysics()->setYPosition(pl->getPhysics()->getYPosition() + pl->getPhysics()->getYVelocity());
        }
        if (isColliding(static_cast<Entity *>(pl2), static_cast<Entity *>(*it)) && (*it)->getHarm())
        {
            pl2->takeDamage();
            pl2->getPhysics()->setXVelocity(-45 * pl2->getPhysics()->getMoveDirection());
            pl2->getPhysics()->setXPosition(pl2->getPhysics()->getXPosition() + pl2->getPhysics()->getXVelocity());
            pl2->getPhysics()->setYVelocity(-15);
            pl2->getPhysics()->setYPosition(pl2->getPhysics()->getYPosition() + pl2->getPhysics()->getYVelocity());
        }
    }

    for (it = LOs.begin(); it != LOs.end(); it++)
    {
        for (it2 = it; it2 != LOs.end(); it2++)
        {
            isColliding(static_cast<Entity *>(*it), static_cast<Entity *>(*it2));
        }
    }
}

void CollisionManager::groundCollision()
{
    vector<Enemy *>::iterator it;
    list<Obstacle *>::iterator it2;

    for (it = LIs.begin(); it != LIs.end(); it++)
    {
        isColliding(static_cast<Entity *>(*it), static_cast<Entity *>(gnd));
    }
    for (it2 = LOs.begin(); it2 != LOs.end(); it2++)
    {
        isColliding(static_cast<Entity *>(*it2), static_cast<Entity *>(gnd));
    }

    isColliding(static_cast<Entity *>(pl), static_cast<Entity *>(gnd));
    isColliding(static_cast<Entity *>(pl2), static_cast<Entity *>(gnd));
}

void CollisionManager::Execute()
{
    obsCollision();
    enemyCollision();
    groundCollision();
}