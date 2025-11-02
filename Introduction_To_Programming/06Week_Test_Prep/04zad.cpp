#include <iostream>

int infDigitSum(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    if(sum > 10){
        sum = infDigitSum(sum);
    }
    return sum;
}
int main(){
    /*Задача 4: Да се въведе цяло положително число n. Да се направи функция, която взима цифрите
     на дадено число и намира сбора им. Трябва да прилагаме тази функция върху n, докато n не стане цифра.*/

     int n;
     std::cout << "Enter value for n: ";
     std::cin >> n;

     std::cout << infDigitSum(n);
}