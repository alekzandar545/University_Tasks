#include "point.hpp"
#pragma once

struct Triangle
{
    Point a,b,c;
};

void translate(Triangle& t, double offsetx, double offsety);