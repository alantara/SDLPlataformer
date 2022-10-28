#pragma once

#include "Entity.hpp"
using namespace Entities;

namespace Entities
{
    class Projectile : public Entity
    {
    private:
        int damage;
    public:
        Projectile();
        ~Projectile();
    };
}