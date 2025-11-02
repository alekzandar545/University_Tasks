#include <iostream>

int findPrimeDenominators(int input){
    int counter = 0;
    for (int i = 2; i <= input; i++)
    {
        if(input % i == 0){
            while(input % i == 0)
                input /= i;
            counter++;
        }
    }
    return counter;
}
void cPrimeDenominators(int a, int b, int c){
    for (int i = a; i < b; i++)
    {
        if(findPrimeDenominators(i) == c)
            std::cout << i << ' ';
    }
    
}
int main(){
    /*Задача 7: Да се направи функция, която при подадени 3 цели положителни числа a, b. c, да се отпечатат всички числа
     в интервал [a, b], които имат c прости делителя.*/
     int a, b, c;
     std::cout << "Enter values for a, b, c: ";
     std:: cin >> a >> b >> c;
     if (a >= b){
        std::cout << "Invalid input";
        return 0;
     }
     cPrimeDenominators(a, b, c);
}