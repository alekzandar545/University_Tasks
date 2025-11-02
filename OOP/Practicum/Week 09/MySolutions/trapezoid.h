#pragma once
#include "quadrilateral.h"

class Trapezoid:public Quadrilateral{
public:
    Trapezoid() = delete;
    Trapezoid(Point a, Point b, Point c, Point d);
};