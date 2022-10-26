

#pragma once 

#include "Scene.hpp"

class Menu : public Scene
{
    public:
    
        virtual void Render() = 0;
        virtual void Update() = 0;

    private:

        
};