#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include "IObject.h"
#include "Transform.h"

struct Properties
{
    public:
        Properties(std::string propTextureID, float propX, float propY, int propWidth, int propHeight, SDL_RendererFlip propFlip = SDL_FLIP_NONE)
        {
            x = propX;
            y = propY;
            m_Flip = propFlip;
            m_Width = propWidth;
            m_Height = propHeight;
            m_TextureID = propTextureID;
        }

        std::string m_TextureID;
        int m_Width, m_Height;
        float x, y;
        SDL_RendererFlip m_Flip;
};

class GameObject : public IObject
{
    public:
        GameObject(Properties* props): m_Width(props->m_Width), m_Height(props->m_Height), m_TextureID(props->m_TextureID), m_Flip(props->m_Flip)
        {
            m_Position = new Transform(props->x, props->y);
        };

        virtual void Draw() = 0;
        virtual void Update(float dt) = 0;
        virtual void Clean() = 0;

    protected:
        Transform* m_Position;
        int m_Width, m_Height;
        std::string m_TextureID;
        SDL_RendererFlip m_Flip;
};

#endif // GAMEOBJECT_H
