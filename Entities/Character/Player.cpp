#include "Player.hpp"
using namespace Entities;
using namespace Characters;

Player::Player(GraphicManager *p_graphM) : Character(p_graphM, 5), bullet(new Projectile(p_graphM, static_cast<Character*>(this)))
{

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
        moveDir = -1;
        physics.setXVelocity(-5);
    }
    if (event->getKeyDown(input.getRight()))
    {
        moveDir = 1;
        physics.setXVelocity(5);
    }
    if (event->getKeyDown(input.getJump()))
    {
        if (getIsGrounded())
            physics.setYVelocity(-35);
    }
    if(event->getKeyDown(input.getFire()))
    {
        bullet->fire(physics.getXPosition(), physics.getYPosition()+30, moveDir);
    }
    move();
    setIsGrounded(false);
}

void Player::render()
{
    if (isActive)
        if(moveDir == 1)
            sprite.render(gfx, physics.getXPosition(), physics.getYPosition());
        else
            sprite.renderFlip(gfx, physics.getXPosition(), physics.getYPosition());
}
