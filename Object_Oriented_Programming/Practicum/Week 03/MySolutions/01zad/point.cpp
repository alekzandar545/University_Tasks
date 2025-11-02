#include "point.hpp"
#include <iostream>

void translate(Point& p, double offsetx, double offsety){
    std::cout << "Old coordinates: " << p.x << ',' << p.y << '\n';
    p.x += offsetx;
    p.y += offsety;
    std::cout << "New coordinates: " << p.x << ',' << p.y << '\n';
}