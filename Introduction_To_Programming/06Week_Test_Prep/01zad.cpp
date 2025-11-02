#include <iostream>

int main(){
    /*Задача 1: Да се въведе цяло положително число n и цяло число x, след което да се въведат
     n на брой цели числа и накрая да се отпечата, колкото от тези числа са по-малки от x.
    */
   int n, x;
   std::cout << "Enter values for n and x: ";
   std::cin >> n >> x;

    int count = 0;
    for (int i = 0; i < n; i++)
    {   
        int current;
        std::cin >> current;
        if(current > x)
            count++;
    }
    std::cout << "numbers bigger than " << x << ": " << count;
    
}