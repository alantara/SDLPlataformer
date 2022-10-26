
#include "EntityM.hpp"

EntityM* EntityM::Instance = nullptr;

EntityM::EntityM()
{

}

EntityM::~EntityM()
{
    
}

void EntityM::AddEntity(Entity* entity)
{
    entityVec.push_back(entity);
}

void EntityM::Update()
{
    std::vector<Entity*>::iterator it;

    for(it = entityVec.begin(); it != entityVec.end(); it++)
    {
        (*it)->Update();
    }
}

void EntityM::Render()
{
    std::vector<Entity*>::iterator it;

    for(it = entityVec.begin(); it != entityVec.end(); it++)
    {
        (*it)->Render();
    }
}

void EntityM::Clean()
{
    std::vector<Entity*>::iterator it;

    for(it = entityVec.begin(); it != entityVec.end(); it++)
    {
        delete *it;
    }
    entityVec.clear();
}