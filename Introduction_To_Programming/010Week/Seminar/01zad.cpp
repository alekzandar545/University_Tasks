#include <iostream>
#include <cstring>

int main(){
    //Задача 1 Да се напише програма, която приема низ и единичен символ и връща, колко пъти се среща символът в низа.
    char a;
    char str[255];
    std::cin >> a;
    std::cin.ignore();
    std::cin.getline(str, 254);
    int counter = 0;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if(str[i] == a)
            counter++;
    }
    std::cout << counter;
    
}