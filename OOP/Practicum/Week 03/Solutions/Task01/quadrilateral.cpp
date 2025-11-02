#include "quadrilateral.hpp"
#include <iostream>

void printCoordinates(std::string prompt, const Quadrilateral& q){
    std::cout << prompt << q.a.x << ',' << q.a.y << '\n'
    << q.b.x << ',' << q.b.y << '\n'
    << q.c.x << ',' << q.c.y << '\n'
    << q.d.x << ',' << q.d.y << '\n';
}
void translate(Quadrilateral& q, double offsetx, double offsety){
    printCoordinates("Old coordinates:\n", q);
    q.a.x += offsetx;
    q.a.y += offsety;
    q.b.x += offsetx;
    q.b.y += offsety;
    q.c.x += offsetx;
    q.c.y += offsety;
    q.d.x += offsetx;
    q.d.y += offsety;
    printCoordinates("New coordinates:\n", q);
}