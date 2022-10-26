
#pragma once

#include "Entity.hpp"

#include <string>

class Plataforms : public Entity
{
    public:

        Plataforms(std::string type = "UndefinedType", int x = 0, int y = 0) : Entity(type, x, y)
        {
            
        }
        ~Plataforms()
        {
            std::cout << "Plataforms Destroyed" << std::endl;
        }

        virtual void Render() = 0;
        virtual void Update() = 0;

    protected:

    private:

};