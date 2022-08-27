#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <SDL.h>
#include <string>

class Animator
{
    public:
        Animator() {};

        void Update();
        void Draw(float x, float y, int spriteWidth, int spriteHeight);
        void SetProps(std::string textureID, int spriteRow, int frameCount, int animSpeed, SDL_RendererFlip flip);

    private:
        int m_SpriteRow, m_SpriteFrame;
        int m_AnimSpeed, m_FrameCount;
        std::string m_TextureID;
        SDL_RendererFlip m_Flip;
};

#endif // ANIMATOR_H
