#ifndef MATH_HEADER
#define MATH_HEADER

#include<cmath>
#include<iostream>
using namespace std;


class Vector2{
    public:
        double x,y;
        double length();
        double sqrlength();
        Vector2(double, double);
        Vector2 operator*(double);
        void normalize();
        double dot(Vector2, Vector2);
         // Two crossed vectors return a scalar pointing in the z direction
        double cross(Vector2, Vector2);
        //A vector crossed with a scalar (z-axis) will return a vector on the 2D Cartesian plane
        Vector2 cross(Vector2, double);
        Vector2 cross(double, Vector2);
};

class Matrix2
{
    public:
        double m00, m01;
        double m10, m11;
        Matrix2(double, double, double, double);
        //Create from angle in radians
        void set(double);
        Matrix2 transpose();
        Vector2 operator*(Vector2);
        Matrix2 operator*(Matrix2);
};

#endif