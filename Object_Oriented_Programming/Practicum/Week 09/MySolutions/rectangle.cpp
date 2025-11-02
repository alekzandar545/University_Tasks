#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(Point a, Point b, Point c, Point d):Parallelogram(a,b,c,d){
    double diag = a.DistanceTo(c)*a.DistanceTo(c);
    double pyth = a.DistanceTo(b)*a.DistanceTo(b) + b.DistanceTo(c)*b.DistanceTo(c);
    std::cout <<'\n' << diag << ' ' << pyth;
    if(diag >= pyth - 0.5 && diag <= pyth +0.5)
        throw std::invalid_argument("Not a rectangle!");
}