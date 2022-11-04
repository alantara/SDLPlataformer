#pragma once

#include <SDL2/SDL.h>

namespace Components
{
    class Physics
    {
    private:
        int xS;
        int yS;

        int xV;
        int yV;

        int xA;
        int yA;

        bool ceilCol;
        bool groundCol;
        bool leftCol;
        bool rightCol;

    public:
        Physics() : xS(0), yS(0), xV(0), yV(0), xA(0), yA(0), ceilCol(false), groundCol(false), leftCol(false), rightCol(false){};
        ~Physics(){};

        void setPhysics(int xPos, int yPos, int xVel, int yVel, int xAcc, int yAcc)
        {
            setXPosition(xPos);
            setYPosition(yPos);

            setXVelocity(xVel);
            setYVelocity(yVel);

            setXAcceleration(xAcc);
            setXAcceleration(yAcc);
        }

        const int getXPosition() const { return xS; }
        const int getYPosition() const { return yS; }
        const int getXVelocity() const { return xV; }
        const int getYVelocity() const { return yV; }
        const int getXAcceleration() const { return xA; }
        const int getYAcceleration() const { return yA; }

        const bool getCeilCollision() const { return ceilCol; }
        const bool getGroundCollision() const { return groundCol; }
        const bool getLeftCollision() const { return leftCol; }
        const bool getRightCollision() const { return rightCol; }

        void setXPosition(int xPos) { xS = xPos; }
        void setYPosition(int yPos) { yS = yPos; }
        void setXVelocity(int xVel) { xV = xVel; }
        void setYVelocity(int yVel) { yV = yVel; }
        void setXAcceleration(int xAcc) { xA = xAcc; }
        void setYAcceleration(int yAcc) { yA = yAcc; }

        void setCeilCollision(bool c) { ceilCol = c; }
        void setGroundCollision(bool c) { groundCol = c; }
        void setLeftCollision(bool c) { leftCol = c; }
        void setRightCollision(bool c) { rightCol = c; }

        void update()
        {
            xV += xA;
            yV += yA;

            xS += xV;
            yS += yV;
        }
    };
}