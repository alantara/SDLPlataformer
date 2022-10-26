
#pragma once

#include <iostream>
#include <string>
#include "Sprite.hpp"

class Entity
{
    public:

        Entity(std::string type = "UndefinedType", int x = 0, int y = 0);
        ~Entity();

        virtual void Render() = 0;
        virtual void Update() = 0;

        void setSprite(Sprite* sp) { sprite = sp; }

    protected:

        std::string entityType;
        int xPos, yPos;
        Sprite* sprite;

    private:
        
};