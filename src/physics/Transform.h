
#pragma once

#include "Vector2D.h"

class Transform
{
    public:
        float x, y;
        Transform(float initX = 0, float initY = 0):x(initX), y(initY) {}

        inline void TranslateX(float translateX)
        {
            x += translateX;
        }
        inline void TranslateY(float translateY)
        {
            y += translateY;
        }
        inline void Translate(Vector2D vec)
        {
            x += vec.x;
            y += vec.y;
        }
};