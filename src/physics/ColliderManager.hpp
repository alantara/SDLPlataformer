
#pragma once


class ColliderManager
{
    public:
        isTileColliding();

        boxColliding();
        
        /*  Instance    */
        static ColliderManager* Getinstance()
        {
            return Instance = Instance ? Instance : new ColliderManager();
        }

    private:
        ColliderManager();
        ~ColliderManager();

        static ColliderManager* Instance;

};