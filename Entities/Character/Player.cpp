#include "Player.hpp"
using namespace Entities;
using namespace Characters;

Player::Player() : Character(5), bullet(new Projectile(true))
{
    physics.setH(64);
    physics.setW(64);
}

Player::~Player()
{
    event = nullptr;
}

void Player::setInputSystem(EventManager *ev, SDL_Scancode l, SDL_Scancode r, SDL_Scancode j, SDL_Scancode f)
{
    event = ev;
    input.setCharacterInput(l, r, j, f);
}

void Player::update()
{
    if (!isActive)
        return;

    if (health <= 0)
    {
        Deactivate();
    }

    physics.setXVelocity(0);

    if (event->getKeyDown(input.getLeft()))
    {
        physics.setMoveDirection(-1);
        physics.setXVelocity(-5);
    }
    if (event->getKeyDown(input.getRight()))
    {
        physics.setMoveDirection(1);
        physics.setXVelocity(5);
    }
    if (event->getKeyDown(input.getJump()))
    {
        if (getIsGrounded())
            physics.setYVelocity(-25);
    }
    if(event->getKeyDown(input.getFire()))
    {
        bullet->fire(physics.getXPosition() - physics.getMoveDirection()*15, physics.getYPosition()+25, physics.getMoveDirection());
    }
    move();
    setIsGrounded(false);
}

void Player::render()
{
    if(isActive){
        if(physics.getMoveDirection() == 1)
            sprite.render(gfx, physics.getXPosition(), physics.getYPosition());
        else
            sprite.renderFlip(gfx, physics.getXPosition(), physics.getYPosition());
    }
}
