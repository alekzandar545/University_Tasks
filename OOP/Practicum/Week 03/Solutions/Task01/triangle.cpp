#include "triangle.hpp"
#include <iostream>

void printCoordinates(std::string prompt, const Triangle& t){
    std::cout << prompt << t.a.x << ',' << t.a.y << '\n'
    << t.b.x << ',' << t.b.y << '\n'
    << t.c.x << ',' << t.c.y << '\n';
}
void translate(Triangle& t, double offsetx, double offsety){
    printCoordinates("Old coordinates:\n", t);
    t.a.x += offsetx;
    t.a.y += offsety;
    t.b.x += offsetx;
    t.b.y += offsety;
    t.c.x += offsetx;
    t.c.y += offsety;
    printCoordinates("New coordinates:\n", t);
}