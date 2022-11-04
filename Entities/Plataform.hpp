
#pragma once

#include "Entity.hpp"
#include <string>

namespace Entities
{
    class Plataform : public Entity
    {
    public:
        Plataform(bool act);
        ~Plataform();

        void update();

    private:
    };
}