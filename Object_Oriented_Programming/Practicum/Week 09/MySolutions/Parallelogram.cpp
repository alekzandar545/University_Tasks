#include "parallelogram.h"

Parallelogram::Parallelogram(Point a, Point b, Point c, Point d):Quadrilateral(a,b,c,d){
    std::cout << a.DistanceTo(d) << ' ' << b.DistanceTo(c) << ' ' << a.DistanceTo(b)<< ' ' << c.DistanceTo(d);
    if(a.DistanceTo(d) != b.DistanceTo(c) || a.DistanceTo(b) != c.DistanceTo(d))
        throw std::invalid_argument("sides aren't parralel!");
}
