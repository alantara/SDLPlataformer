#pragma once

#include<iostream>

class Point {

    public:
        float X, Y;

    public:
        Point(float X=0, float Y=0) : X(X) , Y(Y) {}

        //Adição +
        inline Point operator+(const Point& p2) const {
            return Point(X + p2.X, Y + p2.Y );
        }

        //Adição +=
        inline friend Point operator+=(Point& p1, const Point& p2){
            p1.X += p2.X;
            p1.Y += p2.Y;
            return p1;
        }

        //Subtração -
        inline Point operator-(const Point& p2) const {
            return Point(X - p2.X, Y - p2.Y );
        }

        //Subtração -=
        inline friend Point operator-=(Point& p1, const Point& p2){
            p1.X -= p2.X;
            p1.Y -= p2.Y;
            return p1;
        }

        //Multiplicação *
        inline Point operator*(const float scalar) const {
            return Point(X*scalar, Y*scalar);
        }

        void Log(std::string msg = ""){
            std::cout << msg << "(X Y) = (" << X << " " << Y << ")" << std::endl;
        }
};