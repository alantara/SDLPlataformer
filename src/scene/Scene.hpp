

#pragma once 



class Scene
{
    public:

        Scene(){};
        ~Scene(){};

        virtual void Render() = 0;
        virtual void Update() = 0;

    private:

        
};