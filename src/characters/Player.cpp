#include "Player.h"

#include <SDL.h>
#include <math.h>
#include "TextureManager.h"
#include "EventHandler.h"

Player::Player(Properties* props): Character(props)
{
    m_Rigidbody = new RigidBody();
    m_Animator = new Animator();
    m_Animator->SetProps(m_TextureID, 0, 8, 50, SDL_FLIP_NONE);
}

void Player::Draw()
{
    m_Animator->Draw(m_Position->x, m_Position->y, m_Width, m_Height);
}

void Player::Update(float dt)
{
    int a = 0;

    if (EventHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
    {
        a += -1;
    }
    if (EventHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
    {
        a += 1;
    }

    float force = a * 10 - m_Rigidbody->GetVelocity().x;

    float accelRate = 0.6f;
    if(abs(force) < 7.0f)
        accelRate = 0.8f;
    if(abs(a * 10) < 0.01f)
        accelRate = 6.0f;
    m_Rigidbody->ApplyForceX(force * accelRate);

    m_Position->Translate(m_Rigidbody->GetVelocity());

    m_Rigidbody->Update(dt);
    m_Animator->Update();
}

void Player::Clean()
{
    TextureManager::GetInstance()->Clean();
}
