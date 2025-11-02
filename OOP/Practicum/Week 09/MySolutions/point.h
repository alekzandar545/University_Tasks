#pragma once
#include <iostream>

class Point {
public:
    //constructors
    Point();
    Point(int x, int y);
    ~Point() = default;
    Point& operator=(const Point& other);

    int GetX() const;
    int GetY() const;

    void SetX(const int x);
    void SetY(const int y);

    void Print(std::ostream& os) const;
    void Print() const;

    double DistanceTo(const Point& other) const;

private:
    int x; 
    int y; 
};
