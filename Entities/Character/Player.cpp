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
    position.setX(position.getX() + position.getVX());
    position.setY(position.getY() + position.getVY());

    if (event->getKeyDown(input.getLeft()))
    {
        position.setX(position.getX() - 1);
    }
    if (event->getKeyDown(input.getRight()))
    {
        position.setX(position.getX() + 1);
    }
    if (event->getKeyDown(input.getJump()))
    {
        position.setY(position.getY() - 2);
    }
    position.setY(position.getY() + 1);
}
