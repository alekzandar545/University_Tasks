#include <iostream>
#include <cstring>

bool leq(char* n1, char* n2){
    int diff = abs('2' - 2);
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < strlen(n1); i++)
    {
       num1 = num1*10 + (n1[i] - diff);
    }
    for (int i = 0; i < strlen(n2); i++)
    {
       num2 = num2*10 + (n2[i] - diff);
    }
    if(num2 >= num1)
        return true;
    return false;
    
    
}

int main(){
    char n1[255];
    char n2[255];
    std::cin.getline(n1, 254);
    std::cin.getline(n2, 254);
    if(n2[0] == '0' || n2[0] == '0'){
        std::cout << "Invalid number!";
        return 0;
    }
    std::cout << std::boolalpha << leq(n1, n2);
    /*Задача 1. Да се дефинира функция bool leq ([подходящ тип] n1, [подходящ тип] n2). n1 и n2 са две цели неотрицателни числа, 
    представени чрез символни низове, състоящи се от цифрите на числото (напр. “123”). Функцията да връща истина тогава и само 
    тогава, когато n1 ≤ n2.

    Можете да приемете, че в представянето на числата няма водещи нули.
    Използването на функцията да се демонстрира с подходяща програма.*/

}
