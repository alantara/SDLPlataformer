

#pragma once 

#include "Scene.hpp"

class Menu : public Scene
{
    public:

        Menu(){};
        ~Menu(){};

        virtual void Render() = 0;
        virtual void Update() = 0;

    private:

        
};