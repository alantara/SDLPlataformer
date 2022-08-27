#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Animator.h"
#include "RigidBody.h"

class Player : public Character
{
    public:
        Player(Properties* props);

        virtual void Draw();
        virtual void Update(float dt);
        virtual void Clean();

    private:
        int m_Row, m_Frame, m_FrameCount;
        int m_AnimSpeed;

        Animator* m_Animator;
        RigidBody* m_Rigidbody;
};

#endif // PLAYER_H
