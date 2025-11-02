#include <iostream>
#include <cstring>

int main(){
    //Задача 4 Да се напише програма, която приема низ и принтира максималният брой символи между две големи букви.
    char str[255];
    char lowerCaseStart = 'a';
    char lowerCaseEnd = 'z';
    char upperCaseStart = 'A';
    char upperCaseEnd = 'Z';
    int currentLen = 0;
    int maxLen = 0;

    std::cin.getline(str, 254);
    for (size_t i = 0; i < strlen(str); i++)
    {
        if(str[i] <= lowerCaseEnd && str[i] >= lowerCaseStart)
            currentLen++;
        else if(str[i] <= upperCaseEnd && str[i] >= upperCaseStart){
            if (currentLen > maxLen)
                maxLen = currentLen;
            currentLen = 0;
        }
            
    }
    std::cout << maxLen;
}