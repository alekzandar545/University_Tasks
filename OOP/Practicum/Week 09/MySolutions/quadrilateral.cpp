#include "point.h"
#include "triangle.h"
#include "quadrilateral.h"
#include <cmath>

//construction
Quadrilateral::Quadrilateral(){
    a = {0, 0};
    b = {0, 0};
    c = {0, 0}; 
    d = {0, 0};
}
Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d){
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}
Quadrilateral& Quadrilateral::operator=(const Quadrilateral& other){
    if(&other != this){
        this->a = other.a;
        this->b = other.b;
        this->c = other.c;
        this->d = other.d;
    }
    return *this;
}
//getters
Point Quadrilateral::GetA() const{
    return a;
}
Point Quadrilateral::GetB() const{
    return b;
}
Point Quadrilateral::GetC() const{
    return c;
}
Point Quadrilateral::GetD() const{
    return d;
}
//functionality
double Quadrilateral::GetArea() const{
    //suppose the diagonal is ac
    Triangle t1(a,b,c);
    Triangle t2(a,d,c);
    return t1.GetArea() + t2.GetArea();
}
double Quadrilateral::GetSide(Point x, Point y) const{
    return sqrt((x.GetX() - y.GetX())*(x.GetX() - y.GetX()) + (x.GetY() - y.GetY())*(x.GetY() - y.GetY()));
}
double Quadrilateral::GetPerimeter() const{
    return GetSide(a,b) + GetSide(b,c) + GetSide(c,d) + GetSide(d,a);
}
void Quadrilateral::Print(std::ostream& os) const{
    os << '{' <<'(' << a.GetX() << ',' << a.GetY() << ") "
       << '(' << b.GetX() << ',' << b.GetY() << ") "
       << '(' << c.GetX() << ',' << c.GetY() << ") "
       << '(' << d.GetX() << ',' << d.GetY() << ") " << '}';
}
void Quadrilateral::Print() const{
    std::cout << '{' <<'(' << a.GetX() << ',' << a.GetY() << ") "
       << '(' << b.GetX() << ',' << b.GetY() << ") "
       << '(' << c.GetX() << ',' << c.GetY() << ") "
       << '(' << d.GetX() << ',' << d.GetY() << ") " << '}';
}