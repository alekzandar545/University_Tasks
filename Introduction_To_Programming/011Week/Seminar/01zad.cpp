#include <iostream>
#include <cstring>

char findCapital(char* str, int iterator){
    char capA = 'A';
    char capZ = 'Z';
    if((str[iterator] >= capA && str[iterator] <= capZ) || str[iterator] == '\0')
        return str[iterator];
    return findCapital(str, iterator + 1);
}
int main(){
    /*Задача 1 Да се направи рекурсивна функция, която намира първата главна буква в низ. 
    Ако низът няма главна буква да се връща '\0'. (Може да използвате и pointer arithmetic)*/

    char str[255] = "test tesT";
    std::cout << findCapital(str, 0);

}