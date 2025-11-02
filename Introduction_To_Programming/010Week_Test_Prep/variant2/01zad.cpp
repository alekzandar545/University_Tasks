#include <iostream>
#include <cstring>

const size_t LENGTH = 255;

bool ed(char* n){
    int diff = abs('2' - 2);
    for (size_t i = 0; i < strlen(n); i++)
    {
        if((n[i] - diff) % 2 != 0)
            return false;
    }
    return true;
}


int main(){
    /*Задача 1. Да се дефинира функция bool ed ([подходящ тип] n). n е цяло неотрицателно число, представено чрез 
    символен низ, състоящ се от цифрите на числото (напр. “123”). Функцията да връща истина тогава и само тогава, 
    когато числото се състои само от четни цифри.

    Използването на функцията да се демонстрира с подходяща програма.*/
    char str[LENGTH] = "124";
    std::cout << std::boolalpha << ed(str);
}