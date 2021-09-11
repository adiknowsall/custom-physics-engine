#include "math.h"


// #####################################################################################
// #######################################VECTOR########################################
// #####################################################################################

double Vector2::length(){
    return sqrt(x*x + y*y);
}
double Vector2::sqrlength(){
    return x*x+y*y;
}

Vector2::Vector2(double mx, double my){
    x = mx; y = my;
}

Vector2 Vector2::operator*(double s){
    return Vector2(x*s, y*s);
}

void Vector2::normalize(){
    double len = length();
    x /= len; y /= len;
}

double Vector2::dot(Vector2 a, Vector2 b){
    return a.x*b.x + a.y*b.y;
}

// Two crossed vectors return a scalar pointing in the z direction
double Vector2::cross(Vector2 a, Vector2 b){
    return a.x*b.y - a.y*b.x;
}

//A vector crossed with a scalar (z-axis) will return a vector on the 2D Cartesian plane
Vector2 Vector2::cross(Vector2 v, double s){
    return Vector2(v.y*s, -v.x*s);
}

Vector2 Vector2::cross(double s, Vector2 v){
    return Vector2(-v.y*s, v.x*s);
}

// #####################################################################################
// #######################################MATRIX########################################
// #####################################################################################

//Create from angle in radians
void Matrix2::set(double radians){
    double c = cos(radians);
    double s = sin(radians);
    m00 = c; m01 = -s;
    m10 = s; m11 =  c;
}

Matrix2::Matrix2(double a, double b, double c, double d){
    m00 = a; m01 = b;
    m10 = c; m11 = d;
}

Matrix2 Matrix2::transpose(){
    return Matrix2(m00, m10, m01, m11);
}

Vector2 Matrix2::operator*(Vector2 rhs){
    return Vector2(m00 * rhs.x + m01 * rhs.y, m10 * rhs.x + m11 * rhs.y);
}

Matrix2 Matrix2::operator*(Matrix2 b){
    return Matrix2(m00*b.m00 + m01*b.m10, m00*b.m01 + m01*b.m11, m10*b.m00 + m11*b.m10, m10*b.m01 + m11*b.m11);
}
