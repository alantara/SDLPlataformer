
#pragma once

#include "Entity.hpp"
#include <vector>

class EntityM
{
    public:

        void AddEntity(Entity* entity);

        void Update();
        void Render();

        void Clean();

        /*  Instance    */
        static EntityM* GetInstance()
        {
            return Instance = Instance ? Instance : new EntityM();
        }

    private:

        EntityM();
        ~EntityM();

        std::vector<Entity*> entityVec;

        static EntityM* Instance;

};