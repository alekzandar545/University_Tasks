#pragma once
#include "quadrilateral.h"

class Parallelogram:public Quadrilateral{
public:
    Parallelogram() = delete;
    Parallelogram(Point a, Point b, Point c, Point d);
};