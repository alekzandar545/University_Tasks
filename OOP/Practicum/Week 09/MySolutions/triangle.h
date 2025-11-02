#pragma once
#include "point.h"

class Triangle{
public:
    //construction
    Triangle();
    Triangle(const Point a, const Point b, const Point c);
    ~Triangle() = default;
    Triangle& operator=(const Triangle& other);
    //getters
    Point GetA() const;
    Point GetB() const;
    Point GetC() const;
    //functionality
    double GetArea() const;
    double GetPerimeter() const;
    void Print(std::ostream& o) const;
    void Print() const;
    double GetSide(Point x, Point y) const;
private:
    Point a, b, c;
};