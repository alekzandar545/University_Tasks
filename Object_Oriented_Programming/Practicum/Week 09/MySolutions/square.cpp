#include "square.h"

Square::Square(Point a, Point b, Point c, Point d):Parallelogram(a,b,c,d){
    if(a.DistanceTo(b) != b.DistanceTo(c) || 
    a.DistanceTo(c)*a.DistanceTo(c) != a.DistanceTo(b)*a.DistanceTo(b) + b.DistanceTo(c)*b.DistanceTo(c))
        throw std::invalid_argument("Not a square!");
}