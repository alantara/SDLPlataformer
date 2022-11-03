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

    public:
        Physics() : xS(0), yS(0), xV(0), yV(0), xA(0), yA(0){};
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

        void setXPosition(int xPos) { xS = xPos; }
        void setYPosition(int yPos) { yS = yPos; }
        void setXVelocity(int xVel) { xV = xVel; }
        void setYVelocity(int yVel) { yV = yVel; }
        void setXAcceleration(int xAcc) { xA = xAcc; }
        void setYAcceleration(int yAcc) { yA = yAcc; }

        void update()
        {
            xV += xA;
            yV += yA;

            xS += xV;
            yS += yV;
        }
    };
}