#pragma once

#include "Entity.hpp"

namespace Entities
{
    class Projectile : public Entity
    {
    private:
        int damage;
        bool isPlayerShooted;

    public:
        Projectile(GraphicManager *p_graphM) : Entity(p_graphM){};
        ~Projectile();
    };
}