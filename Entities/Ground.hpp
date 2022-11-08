
#pragma once

#include "Entity.hpp"
using namespace Entities;

namespace Entities
{
    class Ground : public Entity
    {
    private:
    public:
        Ground(GraphicManager *p_graphM){};
        ~Ground(){};

        void update(){};    
    };
}