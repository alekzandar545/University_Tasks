#include <iostream>
#include <cstring>

int main(){
    //Задача 6 Да се напише програма, която намира дали един низ е плаиндром.
    char str[255];
    std::cin.getline(str, 254);
    bool palindrome = 1;
    for (size_t i = 0; i < strlen(str)/2; i++)
    {
        if(str[i] != str[strlen(str) - i - 1])
            palindrome = false;
    }
    std::cout << std::boolalpha << palindrome;
    
}