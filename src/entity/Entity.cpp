
#include "Entity.hpp"

Entity::Entity(std::string type, int x, int y) :
entityType(type),
xPos(x),
yPos(y)
{

}

Entity::~Entity()
{
    delete sprite;
    sprite = nullptr;
}