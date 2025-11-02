#include <iostream>
#include "point.hpp"
#include "triangle.hpp"
#include "quadrilateral.hpp"

int main(){
    Point p = {1, 2};
    translate(p, 2, 3);
    Triangle t = {1,2, 3,4, 5,6};
    translate(t, 2, 3);
    Quadrilateral q = {1,2, 3,4, 5,6, 7,8};
    translate(q, 2, 2);
}