#pragma once
#include "point.h"

class Quadrilateral{
public:
    //construction
    Quadrilateral();
    Quadrilateral(Point a, Point b, Point c, Point d);
    ~Quadrilateral() = default;
    Quadrilateral& operator=(const Quadrilateral& other);
    //getters
    Point GetA() const;
    Point GetB() const;
    Point GetC() const;
    Point GetD() const;
    //functionality
    double GetArea() const;
    double GetPerimeter() const;
    void Print(std::ostream& os) const;
    void Print() const;
    double GetSide(Point x, Point y) const;
private:
    Point a, b, c , d;
};