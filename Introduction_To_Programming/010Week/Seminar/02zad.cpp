#include <iostream>
#include <cstring>

int main(){
    //Задача 2 Да се напише програма, която приема низ и проверява, какъв е броят на малки букви, големи букви и цифри.
    char str[255];
    char lowerCaseStart = 'a';
    char lowerCaseEnd = 'z';
    char upperCaseStart = 'A';
    char upperCaseEnd = 'Z';

    std::cin.getline(str, 254);
    int lowerCount = 0;
    int upperCount = 0;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if(str[i] <= lowerCaseEnd && str[i] >= lowerCaseStart)
            lowerCount++;
        else if(str[i] <= upperCaseEnd && str[i] >= upperCaseStart)
            upperCount++;
    }
    std::cout << lowerCount << ' ' << upperCount;
    
}