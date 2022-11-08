#include "Enemy.hpp"
using namespace Entities;
using namespace Characters;

Enemy::Enemy(GraphicManager *p_graphM, int hp, Player* pl, Player* pl2) : Character(p_graphM, hp), player(pl), player2(pl2)
{

}

Enemy::~Enemy()
{

}

void Enemy::pursue(Player* player)
{
    int plRight = player->getPhysics()->getXPosition() + player->getPhysics()->getW();
    int plLeft = player->getPhysics()->getXPosition();
    int plTop = player->getPhysics()->getYPosition();
    int plBottom = player->getPhysics()->getYPosition() + player->getPhysics()->getH();
            
    int enRight = this->getPhysics()->getXPosition() + this->getPhysics()->getW() + 400;
    int enLeft = this->getPhysics()->getXPosition() - 400;
    int enTop = this->getPhysics()->getYPosition() - 200;
    int enBottom = this->getPhysics()->getYPosition() + this->getPhysics()->getH() + 200;

    if( plRight > enLeft &&
        plLeft < enRight &&
        plTop < enBottom &&
        plBottom > enTop)
    {
        if(plLeft < enLeft + 400)
        {
            this->getPhysics()->setXVelocity(-3);
            moveDir = -1;
        }
        else{
            this->getPhysics()->setXVelocity(3);
            moveDir = 1;
        }
        if(plBottom < enTop + 200)
        {
            this->getPhysics()->setYVelocity(-30);
        }                       
    }
}