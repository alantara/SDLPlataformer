#pragma once

#include <SDL2/SDL.h>

namespace Components
{
    class Physics
    {
    private:
        float xPosition, yPosition;
        float xVelocity, yVelocity;
        float xAcceleration, yAcceleration;
        float mass;

        float xForce, yForce;

        int w;
        int h;

        int moveDir;

    public:
        Physics() : xPosition(0), yPosition(0), xVelocity(0), yVelocity(0), xAcceleration(0), yAcceleration(0), mass(10), xForce(0), yForce(0), w(0), h(0), moveDir(1){};
        ~Physics(){};

        void setPhysics(int xPos, int yPos, int width, int height, int xVel, int yVel, int xAcc, int yAcc)
        {
            setPosition(xPos, yPos);
            setVelocity(xVel, yVel);
            setAcceleration(xAcc, yAcc);

            setW(width);
            setH(height);
        }
        
        const int getMoveDirection() const { return moveDir; }
        void setMoveDirection(int dir) {moveDir = dir;}

        const float getXPosition() const { return xPosition; }
        const float getYPosition() const { return yPosition; }
        const float getXVelocity() const { return xVelocity; }
        const float getYVelocity() const { return yVelocity; }
        const float getXAcceleration() const { return xAcceleration; }
        const float getYAcceleration() const { return yAcceleration; }
        const float getMass() const { return mass; }
        const int getW() const { return w; }
        const int getH() const { return h; }

        void setPosition(float x, float y)
        {
            xPosition = x;
            yPosition = y;
        }
        void setXPosition(float x) { xPosition = x; }
        void setYPosition(float y) { yPosition = y; }

        void setVelocity(float x, float y)
        {
            xVelocity = x;
            yVelocity = y;
        }
        void setXVelocity(float x) { xVelocity = x; }
        void setYVelocity(float y) { yVelocity = y; }

        void setAcceleration(float x, float y)
        {
            xAcceleration = x;
            yAcceleration = y;
        }
        void setXAcceleration(float x) { xAcceleration = x; }
        void setYAcceleration(float y) { yAcceleration = y; }

        void setW(int width) { w = width; }
        void setH(int height) { h = height; }

        void AddForce(float forceX, float forceY)
        {
            xForce += forceX;
            yForce += forceY;
        }

        void UnsetForce()
        {
            xForce = 0;
            yForce = 0;
        }

        void updateVelocity()
        {
            xAcceleration = xForce / mass;
            yAcceleration = yForce / mass + 9.81f;

            xVelocity += xAcceleration;
            yVelocity += yAcceleration;
        }
        void updatePosition()
        {
            xPosition += xVelocity;
            yPosition += yVelocity;
        }
    };
}
