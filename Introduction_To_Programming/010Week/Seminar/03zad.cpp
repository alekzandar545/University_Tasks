#include <iostream>
#include <cstring>

int main(){
    //Задача 3 Да се напише програма, която приема низ. Програмата да прави главните букви малки и малките букви главни.
    char str[255];
    char lowerCaseStart = 'a';
    char lowerCaseEnd = 'z';
    char upperCaseStart = 'A';
    char upperCaseEnd = 'Z';
    int diff = abs('a' - 'A');

    std::cin.getline(str, 254);
    for (size_t i = 0; i < strlen(str); i++)
    {
        if(str[i] <= lowerCaseEnd && str[i] >= lowerCaseStart)
            str[i] -= diff;
        else if(str[i] <= upperCaseEnd && str[i] >= upperCaseStart)
            str[i] += diff;
    }
    std::cout << str;
}