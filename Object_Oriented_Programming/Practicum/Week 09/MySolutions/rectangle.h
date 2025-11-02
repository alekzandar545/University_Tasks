#pragma once
#include "parallelogram.h"

class Rectangle:public Parallelogram{
public:
    Rectangle() = delete;
    Rectangle(Point a, Point b, Point c, Point d);
};