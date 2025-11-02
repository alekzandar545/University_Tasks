#include "point.hpp"
#pragma once

struct Quadrilateral
{
    Point a,b,c,d;
};

void translate(Quadrilateral& q, double offsetx, double offsety);