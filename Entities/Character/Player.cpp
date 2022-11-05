#include "Player.hpp"
using namespace Entities;
using namespace Characters;

Player::Player(GraphicManager *p_graphM) : Character(p_graphM, 5)
{
    isGrounded = false;
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
    applyGravity();    
    
    if (event->getKeyDown(input.getLeft()))
    {
        position.setX(position.getX() - 2);
    }
    if (event->getKeyDown(input.getRight()))
    {
        position.setX(position.getX() + 2);
    }
    if (event->getKeyDown(input.getJump()))
    {
        if(getIsGrounded())
            position.setVY(-100);
    }
    move();
    setIsGrounded(false);
}
