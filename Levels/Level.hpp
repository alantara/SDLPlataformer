#pragma once

#include "Ente.hpp"
#include "EntityList.hpp"
#include "Map.hpp"
using namespace Lists;

namespace Levels
{
class Level : public Ente
{
protected:
    EntityList entities;
    Map map;

public:
    Level();
    ~Level();

    Map* getMap() { return &map; }

    void render(SDL_Renderer* renderer);
    virtual void update() = 0;
    void manageCollision();
    EntityList* getEntityList() {return &entities;}
};
}