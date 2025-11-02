#include <iostream>
#include <cstring>

void collapse(char* str, unsigned int index){
    for (size_t i = index; i < strlen(str); i++)
    {
        str[i] = str[i+1];
    }
    
}
void shift(char*str, unsigned int index){
    for (size_t i = strlen(str); i >= index; i--)
    {
        str[i+1] = str[i];
    }
}

void shake(char* s){
    char element;
    unsigned index = 1;
    for (size_t i = 1; i < strlen(s); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z'){
            element = s[i];
            collapse(s, i);
            shift(s, index);
            s[index] = element;
            index++;
        }
    }
    
}

int main(){
    /*Задача 4. Да се дефинира функция 

    void shake (char *s)

    Функцията да премества всички главни латински букви на низа s в началото му, като реда им една спрямо друго се запазва,
    както се запазва и реда на останалите елементи. Например, ако s е низа “Hello World!”, след приложение на shake(s),
    съдържанието на s ще бъде “HWello orld!”.*/
    unsigned size;
    std::cin >> size;
    char* str = new(std::nothrow) char[size];
    if(!str){
        std::cout << "Memory error";
        return 0;
    }
    std::cin.ignore();
    std::cin.getline(str, size-1);
    //std::cout << str;
    shake(str);

    std::cout << str;
    delete[] str;
}