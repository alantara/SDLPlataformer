#pragma once

#include "Entity.hpp"
using namespace Entities;

namespace Entities
{
    namespace Plataform
    {
        class Plataform : public Entity
        {
        public:
            Plataform(){};
            ~Plataform(){};

            virtual void update() = 0;

        protected:
        private:
        };
    }
}