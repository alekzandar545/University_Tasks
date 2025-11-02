#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

double Distance (int x1, int y1, int x2, int y2){
    double result = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    result *= 1000;
    int integer = result;
    return integer / 1000.0;
}

int main(){
    cout << Distance(1, 1, 4, 3);
}