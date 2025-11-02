#include <iostream>
#include <math.h>
#include <cmath>

int main(){
    /*Задача 6: Да се напише функция, която принтира всички Armstrong числа в интервалът [1, 1000]
    . Armstrong число е такова число е такова, число на което сумата от цифрите му вдигната на степен
     броя цифри на числото, да дава самото число.

    Изход:
    1 2 3 4 5 6 7 8 9 81 512*/
    for (int i = 1; i < 1001; i++)
    {
        int sum = 0;
        int current = i;
        int counter = 0;
        while(current != 0){
            sum += current % 10;
            current /= 10;
            counter++;
        }
        if (pow(sum, counter) == i)
            std::cout << i << ' ';
    }
    
}