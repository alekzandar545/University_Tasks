#include <iostream>
#include <math.h>

using namespace std;

int main(){

    //sphere
    double r;
    cout << "enter the radius of a sphere / cone: " << endl;
    cin >> r;
    double volumeSphere = (4 * 3.14159 * pow(r, 3)) / 3;
    cout << "the volume of the sphere is: " << volumeSphere << endl;
    //cone
    double h;
    cout << "enter the height of the cone: " << endl;
    cin >> h;
    double volumeCone = (2 * 3.14159 * r * h) / 3;
    cout << "the volume of the cone is: " << volumeCone;
}