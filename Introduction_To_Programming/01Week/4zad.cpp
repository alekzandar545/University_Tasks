#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double a,b,c;
    double r;
    //triangle
    cout << "enter the sides of a triangle a,b,c: " << endl;
    cin >> a >> b >> c;
    double halfPer = (a + b + c)/2;
    double result = halfPer * sqrt((halfPer - a) * (halfPer - b) * (halfPer - c));
    cout << fixed << setprecision(2);
    cout << "the area of the triangle is: " << result << endl;
    //sphere
    cout << "enter the radius of a sphere: " << endl;
    cin >> r;
    double volume = 4 * 3.14159 * pow(r, 2);
    cout << "the area of the sphere is: " << volume;

}