
#pragma once

#include <SDL2/SDL.h>
#include "Vector2D.h"

class RigidBody
{
    public:
        RigidBody();

        inline void SetMass(float mass)
        {
            m_Mass = mass;
        }
        inline void SetGravity(float gravity)
        {
            m_Gravity = gravity;
        }

        inline void ApplyForce(Vector2D force)
        {
            m_Force = force;
        }
        inline void ApplyForceX(float forceX)
        {
            m_Force.x = forceX;
        }
        inline void ApplyForceY(float forceY)
        {
            m_Force.y = forceY;
        }
        inline void UnsetForce()
        {
            m_Force.x = 0;
            m_Force.y = 0;
        }

        inline void Update(float dt)
        {
            m_Acceleration.x = m_Force.x / m_Mass;
            m_Acceleration.y = m_Gravity + m_Force.y / m_Mass;

            m_Velocity = m_Velocity + m_Acceleration * dt;
            m_Position = m_Position + m_Velocity * dt;
        }

        inline Vector2D GetVelocity()
        {
            return m_Velocity;
        }
        inline Vector2D GetPosition()
        {
            return m_Position;
        }

    private:
        float m_Gravity, m_Mass;

        Vector2D m_Force;
        Vector2D m_Position, m_Velocity, m_Acceleration;
};