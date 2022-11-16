#include "Entity.hpp"
using namespace Entities;

Entity::Entity() : isActive(true), isGrounded(false)
{
}

Entity::~Entity()
{
}

void Entity::applyGravity()
{
    physics.setYAcceleration(5);
}

void Entity::move()
{
    applyGravity();

    physics.setYVelocity(physics.getYVelocity() + physics.getYAcceleration());
    if (physics.getYVelocity() > 15)
        physics.setYVelocity(15);

    physics.setXPosition(physics.getXPosition() + physics.getXVelocity());
    physics.setYPosition(physics.getYPosition() + physics.getYVelocity());
}

void Entity::render()
{
    if (isActive)
        sprite.render(physics.getXPosition(), physics.getYPosition(), physics.getMoveDirection());
}