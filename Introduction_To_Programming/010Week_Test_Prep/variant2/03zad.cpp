#include <iostream>
#include <math.h>
int main(){
    /*Задача 3. От стандартния вход се въвежда естественото число n, следвано от други 2 ✕ n на брой дробни числа 
    (представени чрез тип double) x0, y0, x1, y1,...,xn-1, yn-1. Двойките (xi, yi) са декартови координати на точки 
    в евклидовата равнина. Да се напише програма, която намира и извежда на стандартния изход лицето на квадрат с 
    възможно най-малка площ, чиито страни са успоредни на координатните оси и който съдържа всички въведени точки.
    Пример: за редицата от точки (0, 0), (-1, 0), (2, 1) програмата ще изведе 9.*/
    int n;
    std::cin >> n;
    double* coordinates = new(std::nothrow) double[2*n];
    if(!coordinates){
        std::cout << "Memory error!";
        return -1;
    }
    for (size_t i = 0; i < n*2; i++)
    {
        std::cin >> coordinates[i];
    }
    double maxX = coordinates[0], minX = coordinates[0];
    double maxY = coordinates[1], minY = coordinates[1];
    for (size_t i = 0; i < 2*n; i++)
    {
        if(i % 2 == 0){ //x
            if(coordinates[i] < minX)
                minX = coordinates[i];
            else if(coordinates[i] > maxX)
                maxX = coordinates[i];
        }
        if(i % 2 != 0){ //y
            if(coordinates[i] < minY)
                minY = coordinates[i];
            else if(coordinates[i] > maxY)
                maxY = coordinates[i];
        }
    }
    int longerSide;
    if(abs(minX - maxX) > abs(minY - maxY))
        longerSide = abs(minX - maxX);
    else
        longerSide = abs(minY - maxY);
    double area = longerSide*longerSide;
    std::cout << area;

    delete[] coordinates;
}