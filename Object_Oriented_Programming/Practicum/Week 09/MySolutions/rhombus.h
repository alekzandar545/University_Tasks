#pragma once
#include "parallelogram.h"

class Rhombus:public Parallelogram{
public:
    Rhombus() = delete;
    Rhombus(Point a, Point b, Point c, Point d);
};