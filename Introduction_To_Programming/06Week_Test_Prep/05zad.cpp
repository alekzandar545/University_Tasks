#include <iostream>

int bounces(double x, double y){
    int minHeight = 1;
    double bounceHeight = x * y;
    int counter = 0;
    while (bounceHeight > minHeight){
        counter++;
        bounceHeight = bounceHeight * y;
    }

    return counter;
}
int main(){
    /*Задача 5: Пешо пуска топка от някаква височина x, топката има коефицент на отскок y.
    При пускане на топката след отскока тя достига височина x * y. Да се напише функция,
    която при подадени x и y, намира колко отскока ще направи топката, така че максималната и височина да е > 1.*/

    double x, y;
    std::cout << "Enter values for the height x and coef y: ";
    std::cin >> x >> y;

    std::cout << "Number of bounces: " << bounces(x, y);

}