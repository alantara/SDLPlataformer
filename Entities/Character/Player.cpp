#include "Player.hpp"
using namespace Entities;
using namespace Characters;

Player::Player(bool act, int hp) : Character(hp)
{
    id = 1;
    active = act;
}

Player::~Player()
{
    event = nullptr;
}

void Player::setInputSystem(EventManager *ev, SDL_Scancode l, SDL_Scancode r, SDL_Scancode j)
{
    event = ev;
    input.setCharacterInput(l, r, j);
}

void Player::update()
{
    physics.setXAcceleration(0);
    if (event->getKeyDown(input.getLeft()))
    {
        physics.setXAcceleration(-1);
    }
    if (event->getKeyDown(input.getRight()))
    {
        physics.setXAcceleration(1);
    }
    if (event->getKeyDown(input.getJump()))
    {
        physics.setYAcceleration(-3);
    }

    physics.setYAcceleration(0);

    physics.update();

    position.setX(physics.getXPosition());
    position.setY(physics.getYPosition());
}
