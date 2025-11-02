#include "trapezoid.h"

Trapezoid::Trapezoid(Point a, Point b, Point c, Point d):Quadrilateral(a,b,c,d){
    if(abs(a.GetY()-d.GetY()) != abs(b.GetY()-c.GetY()) && abs(a.GetX()-d.GetX()) != abs(b.GetX()-c.GetX()))
        throw std::invalid_argument("Points do not form a trapezoid!");
}