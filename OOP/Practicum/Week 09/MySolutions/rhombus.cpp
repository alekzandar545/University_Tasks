#include "rhombus.h"

Rhombus::Rhombus(Point a, Point b, Point c, Point d):Parallelogram(a,b,c,d){
    if(a.DistanceTo(b) != b.DistanceTo(c))
        throw std::invalid_argument("Not a rhombus!");
}