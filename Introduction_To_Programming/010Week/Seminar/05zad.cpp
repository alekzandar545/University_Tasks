#include <iostream>
#include <cstring>

int main(){
    //Задача 5 Да се напише програма, която приема низ и премахва всички празни места в него(' ').
    char str[255];
    std::cin.getline(str, 254);
    while(strchr(str, ' ')){
        int substringLen = strlen(strchr(str, ' '));
        for (size_t i = strlen(str) - substringLen; i < strlen(str); i++)
        {
            str[i] = str[i+1];
        }
    }
    std::cout << str;
}