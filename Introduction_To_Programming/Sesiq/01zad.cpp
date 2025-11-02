#include <iostream>
#include <cstring>

void removeUpper(char* str){
    for (size_t i = 0; i < strlen(str); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z'){
            for (size_t j = i; j < strlen(str) - 1; j++)
            {
                str[j] = str[j+1];
            }
            str[strlen(str) - 1] = '\0';
            i--;
        }
    }
    
}

int main(){
    /*Задача 1. Да се дефинира функция 

    void removeUpper (char *s)

    Функцията да премахва всички големи латински букви от низа s. Например, ако s е низа “Hello World!”,
    след приложение на removeUpper(s), съдържанието на s ще бъде “ello orld!”.*/
    char str[256];
    std::cin.getline(str, 255);
    removeUpper(str);
    std::cout << str;


}