#include <iostream>

size_t Strlen(const char* str){
    size_t counter = 0;
    while(str[counter] != '\0')
        counter++;
    return counter;
}

int Strcmp(const char* str1, const char* str2){
    if(Strlen(str1) < Strlen(str2))
        return -1;
    else if(Strlen(str1) > Strlen(str2))
        return 1;
    return 0;
}

void Strcat(char* destination, const char* source){
    int startLen = Strlen(destination);
    for (size_t i = startLen; i < Strlen(source) + startLen; i++)
    {
        destination[i] = source[i - startLen];
    }
}

void Strcpy(char* destination, const char* source){
    for (size_t i = 0; i < Strlen(source); i++)
    {
        destination[i] = source[i];
    }
    destination[Strlen(source)] = '\0';
    
}
int main(){
    /*Да се имплементират следните функциите за символни низове:
    
    size_t strlen(const char* str); - намира дължината на символния низ str.

    int strcmp(const char* str1, const char* str2); - сравнява лексикографски двата символни низа, 
    подадени като аргументи.

    void strcat(char* destination, const char* source); - конкатенира двата символни низа, подадени като аргументи, 
    резултатът се записва в destination. (Приемаме, че в destination има достатъчно място за добавянето на source)

    void strcpy(char* destination, const char* source); - копира съдържанието на source низа в destination. (Приемаме, 
    че в destination има достатъчно място за копирането на source)

    Можете да откриете повече информация за тяхното действие и това на други функции за символни низове тук:*/
}