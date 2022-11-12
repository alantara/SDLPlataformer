#include "Enemy.hpp"
using namespace Entities;
using namespace Characters;

Enemy::Enemy(int hp, Player* pl, Player* pl2, bool sh) : Character(hp), player(pl), player2(pl2), shooter(sh)
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
            
    int enRight = this->getPhysics()->getXPosition() + this->getPhysics()->getW() + 128;
    int enLeft = this->getPhysics()->getXPosition() - 128;
    int enTop = this->getPhysics()->getYPosition() - 90;
    int enBottom = this->getPhysics()->getYPosition() + this->getPhysics()->getH() + 90;

    if( plRight > enLeft &&
        plLeft < enRight &&
        plTop < enBottom &&
        plBottom > enTop)
    {
        if(plLeft < enLeft + 128)
        {
            getPhysics()->setMoveDirection(-1);
            this->getPhysics()->setXVelocity(physics.getMoveDirection()*physics.getXVelocity());
        }
        else{
            getPhysics()->setMoveDirection(1);
            this->getPhysics()->setXVelocity(physics.getMoveDirection()*physics.getXVelocity());
        }                      
    }
}