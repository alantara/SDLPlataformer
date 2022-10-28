#pragma once

#include "Ente.hpp"
#include "EntityList.hpp"
using namespace Lists;

namespace Levels
{
class Level : public Ente
{
private:
    EntityList entities;
public:
    Level();
    ~Level();

    virtual void update();
    void manageCollision();
};
}