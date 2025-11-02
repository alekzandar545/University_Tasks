#include <iostream>
#include <math.h>

int polynomeSum(int n, double x){
    double sum = 0;
    std::cout << "Enter n+1 coefficients: ";
    for (int i = 0; i <= n; i++)
    {
        int coef = 0;
        std::cin >> coef;

        sum += coef * pow(x, n-i);
    }
    return sum;
}
int main(){
    //Задача 3: Да се напише функция, която при подадени цяло положително число n и реално число x,
    //да въвежда n на брой реални числа и да пресмята стойността на полинома: a1 * x^(n) + a2 * x^(n-1) + … + an * x + an+1
    int n;
    double x;
    std::cout << "Enter values for n and x: ";
    std:: cin >> n >> x;

    std::cout << polynomeSum(n, x);

    


}