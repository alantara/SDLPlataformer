#include "Entity.hpp"
using namespace Entities;

Entity::Entity(): isActive(true), isGrounded(false)
{

}

Entity::~Entity()
{

}

void Entity::applyGravity(int id)
{
    if (id == 3)
    {
        physics.setYAcceleration(1);
    }
    else
    {
        if (physics.getYVelocity() <= 0)
            physics.setYAcceleration(3);
        else
            physics.setYAcceleration(10);
    }
}
void Entity::move(int id)
{
    applyGravity(id);

    physics.setYVelocity(physics.getYVelocity() + physics.getYAcceleration());
    if (physics.getYVelocity() > 15)
        physics.setYVelocity(15);

        physics.setXPosition(physics.getXPosition() + physics.getXVelocity());
        physics.setYPosition(physics.getYPosition() + physics.getYVelocity());
}

void Entity::render()
{
    sprite.render(gfx, physics.getXPosition(), physics.getYPosition());
}