
#pragma once

#include "GraphicManager.hpp"
using namespace Managers;
#include "Plataform.hpp"
using namespace Obstacles;
#include "Entity.hpp"

namespace Entities
{
    class Ground : public Entity
    {
    private:
        Plataform** platvector;

    public:
        Ground()
        {
            platvector = (Plataform**)malloc(17*sizeof(Plataform*));
            for(int i = 0 ; i < 17 ; i++)
            {
                platvector[i] = new Plataform();
                platvector[i]->getPhysics()->setPosition(i*129-129, GraphicManager::getInstance()->getHeight() - 44);
            }
        };
        ~Ground(){};

        void update(){};
        void render() override
        {
            for(int i = 0 ; i < 17 ; i++)
            {
                platvector[i]->render();
            }
        }  
    };
}