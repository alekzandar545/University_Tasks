#include <iostream>
#include <cmath>
#include <iomanip>

struct Point{
    double x,y;
};
struct Triangle
{
    Point a, b, c;
};

double CinAndValidate(double input){
    std::cin >> input;
    while(input < -100 || input > 100){
        std::cout << "Invalid input, try again!";
        std::cin >> input;
    }
    return input;
}
double FindSide(Point a, Point b){
    double absX = abs(a.x - b.x);
    double absY = abs(a.y - b.y);
    return sqrt(absX*absX + absY*absY);
}
double FindArea(Triangle triangle){
    double a, b, c;
    a = FindSide(triangle.a, triangle.b);
    b = FindSide(triangle.b, triangle.c);
    c = FindSide(triangle.a, triangle.c);
    double halfPer = (a + b + c)/2;
    return sqrt(halfPer*(halfPer - a)*(halfPer - b)*(halfPer - c));
}

int main(){
    /*
    Задача 1: Въвежда се цяло число N и после N тригъгълника в равнината, определени от 3 точки(6 координати). Отпечатайте тригълниците сортирани по лицата им.
    Input Format
    На първият ред се въвежда цяло число N, на следващите N реда се въвеждат по 6 цели числа, координатите на триъгълника.

    Constraints
    1 <= N <= 1000
    -100 <= xi, yi <= 100
    Output Format
    Да се принтират лицата на всички триъгълници, сортирани в нарастващ ред и разделени с един интервал.

    Sample Input
*/
    unsigned N;
    std::cin >> N;
    if(N < 1 || N > 1000){
        std::cout << "Inavlid input";
        return 0;
    }
    Triangle* triangles = new(std::nothrow) Triangle[N];
    if(!triangles){
        std::cout << "Memory error!";
        return 0;
    }
    for (size_t i = 0; i < N; i++)
    {
        triangles[i].a.x = CinAndValidate(triangles[i].a.x);
        triangles[i].a.y = CinAndValidate(triangles[i].a.y);
        triangles[i].b.x = CinAndValidate(triangles[i].b.x);
        triangles[i].b.y = CinAndValidate(triangles[i].b.y);
        triangles[i].c.x = CinAndValidate(triangles[i].c.x);
        triangles[i].c.y = CinAndValidate(triangles[i].c.y);
    }

    for (size_t i = 0; i < N; i++)
    {
        std::cout << std::fixed << std::setprecision(2) << FindArea(triangles[i]) << " ";
    }
    

    delete[] triangles;
    return 0;
}