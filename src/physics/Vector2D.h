
#pragma once

class Vector2D
{
    public:
        float x, y;
        Vector2D(float initX = 0, float initY = 0):x(initX), y(initY){}

        //Addition
        inline Vector2D operator+(const Vector2D& v2) const
        {
            return Vector2D(x + v2.x, y + v2.y);
        }

        //Subtraction
        inline Vector2D operator-(const Vector2D& v2) const
        {
            return Vector2D(x - v2.x, y - v2.y);
        }

        //Multiply by scalar
        inline Vector2D operator*(const float scalar) const
        {
            return Vector2D(x * scalar, y * scalar);
        }
};