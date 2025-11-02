#include <cmath>
#include "triangle.h"

//construction
Triangle::Triangle(){
    a = {0, 0};
    b = {0, 0};
    c = {0, 0};
}
Triangle::Triangle(const Point a, const Point b, const Point c){
    this->a = a;
    this->b = b;
    this->c = c;
}
Triangle& Triangle::operator=(const Triangle& other){
    if(&other != this){
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;
    }
    return *this;
}
//getters
Point Triangle::GetA() const{
    return a;
}
Point Triangle::GetB() const{
    return b;
}
Point Triangle::GetC() const{
    return c;
}
//functionality
double Triangle::GetArea() const{
    //using determinant
    return (a.GetX()-c.GetX())*(b.GetY()-c.GetY()) * (a.GetY()-c.GetY())*(b.GetY()-c.GetY());
}
//find side function needed
double Triangle::GetSide(Point x, Point y) const{
    return sqrt((y.GetX() - x.GetX())*(y.GetX() - x.GetX()) + (y.GetY() - x.GetY())*(y.GetX() - x.GetX()));
}
double Triangle::GetPerimeter() const{
    return GetSide(a,b) + GetSide(b,c) + GetSide(c,a);
}
void Triangle::Print(std::ostream& os) const{
    os << '{' <<'(' << a.GetX() << ',' << a.GetY() << ") "
       << '(' << b.GetX() << ',' << b.GetY() << ") "
       << '(' << c.GetX() << ',' << c.GetY() << ") " << '}';
}
void Triangle::Print() const{
    std::cout << '{' <<'(' << a.GetX() << ',' << a.GetY() << ") "
       << '(' << b.GetX() << ',' << b.GetY() << ") "
       << '(' << c.GetX() << ',' << c.GetY() << ") " << '}';
}