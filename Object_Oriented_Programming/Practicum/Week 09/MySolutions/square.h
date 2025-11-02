#pragma once
#include "parallelogram.h"

class Square:public Parallelogram{
public:
    Square() = delete;
    Square(Point a, Point b, Point c, Point d);
};