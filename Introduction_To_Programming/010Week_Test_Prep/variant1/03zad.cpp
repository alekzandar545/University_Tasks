#include <iostream> 
#include <cstring>

const size_t SIZE = 1024;

int main(){
    /*Задача 3. От стандартния вход се въвежда естественото число n, следвано от други 2 ✕ n на брой дробни 
    числа (представени чрез тип double) x0, y0, x1, y1,...,xn-1, yn-1. Двойките (xi, yi) са декартови координати 
    на точки в евклидовата равнина. Да се намери правоъгълник с възможно най-малка площ, чиито страни са успоредни 
    на координатните оси и който съдържа всички въведени точки. Да се изведат на
    стандартния изход координатите на горния ляв ъгъл на правоъгълника и дължините на страните му.
    Пример: За редицата от точки (0, 0), (-1, 0), (2, 1) програмата ще изведе -1 1 3 1.*/
    int n;
    std::cin >> n;
    double coordinates[SIZE];
    for (size_t i = 0; i < 2*n; i++)
    {
        std::cin >> coordinates[i];
    }
    //gotta top left = minX and maxY
    //side1 = abs(minX - maxX) side2 = abs(minY - maxY)
    double minX = coordinates[0], minY = coordinates[1];
    double maxX = coordinates[0], maxY = coordinates[1];
    for (size_t i = 0; i < 2*n; i++)
    {
        if(i % 2 == 0){ //x
            if(coordinates[i] > maxX)
                maxX = coordinates[i];
            if(coordinates[i] < minX)
                minX = coordinates[i];
        }
        else if(i % 2 != 0){ //y
            if(coordinates[i] > maxY)
                maxY = coordinates[i];
            if(coordinates[i] < minY)
                minY = coordinates[i];
        }
    }
    std::cout << minX << ' ' << maxY << ' ' << abs(minX - maxX) << ' ' << abs(minY - maxY);
    
    
}