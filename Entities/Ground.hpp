
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
        int size;

    public:
        Ground(): size(17)
        {
            platvector = (Plataform**)malloc(size*sizeof(Plataform*));
            for(int i = 0 ; i < size ; i++)
            {
                platvector[i] = new Plataform();
                platvector[i]->getPhysics()->setPosition(i*129-129, GraphicManager::getInstance()->getHeight() - 44);
            }
        }
        ~Ground()
        {
            for(int i = 0; i < size ; i++)
            {
                delete platvector[i];
                platvector[i] = nullptr;
            }
        }

        void update(){};
        void render() override
        {
            for(int i = 0 ; i < size ; i++)
            {
                platvector[i]->render();
            }
        }  
    };
}