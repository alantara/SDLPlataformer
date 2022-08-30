#include "Animator.h"

#include "../graphics/TextureManager.h"

void Animator::Update()
{
    m_SpriteFrame = SDL_GetTicks()/m_AnimSpeed % m_FrameCount;
}

void Animator::Draw(float x, float y, int spriteWidth, int spriteHeight)
{
    TextureManager::GetInstance()->DrawFrame(m_TextureID, x, y, spriteWidth, spriteHeight, m_SpriteRow, m_SpriteFrame);
}

void Animator::SetProps(std::string textureID, int spriteRow, int frameCount, int animSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE)
{
    m_TextureID = textureID;
    m_SpriteRow = spriteRow;
    m_FrameCount = frameCount;
    m_AnimSpeed = animSpeed;
    m_Flip = flip;
}
