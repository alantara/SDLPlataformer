#include "CollisionManager.hpp"
#include <iostream>

using namespace Managers;

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

bool CollisionManager::isColliding(const SDL_Rect *hb1, const SDL_Rect *hb2)
{
    int x1 = hb1->x;
    int y1 = hb1->y;
    int w1 = hb1->w;
    int h1 = hb1->h;

    int x2 = hb2->x;
    int y2 = hb2->y;
    int w2 = hb2->w;
    int h2 = hb2->h;

    if (x1 + w1 > x2 && x1 < x2 + w2 && y1 + h1 > y2 && y1 < y2 + h2)
    {
        return true;
    }
    return false;
}

int CollisionManager::sideColliding(Character *ch, Entity *ent2)
{
    int x1 = ch->getPosition()->getX();
    int y1 = ch->getPosition()->getY();
    int w1 = ch->getHitBox()->w;
    int h1 = ch->getHitBox()->h;
    int Vx = ch->getPhysics().getXVelocity();
    int Vy = ch->getPhysics().getYVelocity();

    int x2 = ent2->getPosition()->getX();
    int y2 = ent2->getPosition()->getY();
    int w2 = ent2->getHitBox()->w;
    int h2 = ent2->getHitBox()->h;

    if (x1 + w1 + Vx > x2 &&
        x1 + Vx < x2 + w2 &&
        y1 + h1 > y2 &&
        y1 < y2 + h2)
    {
        if (Vx > 0)
        {
            ch->setPosition(x2 - w1, y1);
            ch->setPhysics(x2 - w1, y1, 0, Vy, 0, ch->getPhysics().getYAcceleration());
            ch->getHitBox()->x = x2 - w1;
            return 1; // Right Collision
        }
        else if (Vx < 0)
        {
            ch->setPosition(x2 + w2, y1);
            ch->setPhysics(x2 + w2, y1, 0, Vy, 0, ch->getPhysics().getYAcceleration());
            ch->getHitBox()->x = x2 + w2;
            return 3; // Left Collision
        }
    }

    if (x1 + w1 > x2 &&
        x1 < x2 + w2 &&
        y1 + h1 + Vy > y2 &&
        y1 + Vy < y2 + h2)
    {
        if (Vy > 0)
        {
            ch->setPosition(x1, y2 - h1);
            ch->setPhysics(x1, y2 - h1, Vx, 0, ch->getPhysics().getXAcceleration(), ch->getPhysics().getYAcceleration());
            ch->getHitBox()->y = y2 - h1;
            return 4; // Top Collision
        }
        else if (Vy < 0)
        {
            ch->setPosition(x1, y2 + h2);
            ch->setPhysics(x1, y2 + h2, Vx, 0, ch->getPhysics().getXAcceleration(), ch->getPhysics().getYAcceleration());
            ch->getHitBox()->y = y2 + h2;

            return 2; // Bottom Collision
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

    for (itPla; itPla != LPs.end(); itPla++)
    {
        sideColliding(static_cast<Character *>(pl), static_cast<Entity *>(*itPla));
    }
}