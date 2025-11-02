#include <iostream>
#include "point.h"
#include "cmath"

//construct
Point::Point() {
    x = 0;
    y = 0;
}
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
Point& Point::operator=(const Point& other){
    if(&other != this){
        x = other.GetX();
        y = other.GetY();
    }
    return *this;
}
//getters
int Point::GetX() const {
    return x;
}
int Point::GetY() const {
    return y;
}
//setters
void Point::SetX(const int x) {
    this->x = x;
}
void Point::SetY(const int y) {
    this->y = y;
}
//works for any stream;
void Point::Print(std::ostream& os) const {
    os << '(' << x << ',' << y << ')';
}
void Point::Print() const {
    std::cout << '(' << x << ',' << y << ')';
}

double Point::DistanceTo(const Point& other) const {
    int newX = other.GetX() - x;
    int newY = other.GetY() - y;
    return sqrt(newX*newX + newY*newY);
}